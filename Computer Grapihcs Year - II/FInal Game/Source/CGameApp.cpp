#include "CGameApp.h"

USHORT Width = (int)GetSystemMetrics(SM_CXSCREEN);
USHORT Height = (int)GetSystemMetrics(SM_CYSCREEN);

extern HINSTANCE g_hInst;

int score;
int score2;
char Score[] = "Score Player1";
char Score2[] = "Score Player2";

CGameApp::CGameApp()
{
	m_hWnd			= NULL;
	m_hIcon			= NULL;
	m_hMenu			= NULL;
	m_pBBuffer		= NULL;
	m_pPlayer		= NULL;
	m_pPlayerTwo = NULL;
	m_Street        = NULL;
	m_Railroad      = NULL;
	invincibleTime	= 0;
	score = 1;
	score2 = 1;


	for (int i = 0; i < NUMBER_OF_CAR; i++)
	{
		m_Car[i] = NULL;
	}

	for (int i = 0; i < NUMBER_OF_TRAIN; i++)
	{
		m_Train[i] = NULL;
	}

	m_LastFrameRate = 0;
}
CGameApp::~CGameApp()
{
	// Shut the engine down
	ShutDown();
}

bool CGameApp::InitInstance( LPCTSTR lpCmdLine, int iCmdShow )
{
	// Create the primary display device
	if (!CreateDisplay()) { ShutDown(); return false; }

	// Build Objects
	if (!BuildObjects()) 
	{ 
		MessageBox( 0, _T("Failed to initialize properly. Reinstalling the application may solve this problem.\nIf the problem persists, please contact technical support."), _T("Fatal Error"), MB_OK | MB_ICONSTOP);
		ShutDown(); 
		return false; 
	}

	// Set up all required game states
	SetupGameState();

	// Success!
	return true;
}

//-----------------------------------------------------------------------------
// Name : CreateDisplay ()
// Desc : Create the display windows, devices etc, ready for rendering.
//-----------------------------------------------------------------------------
bool CGameApp::CreateDisplay()
{
	LPTSTR			WindowTitle		= _T("Trainz");
	LPCSTR			WindowClass		= _T("Traninz");
	USHORT			Width			= 800;
	USHORT			Height			= 600;
	RECT			rc;
	WNDCLASSEX		wcex;


	wcex.cbSize			= sizeof(WNDCLASSEX);
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= CGameApp::StaticWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= g_hInst;
	wcex.hIcon			= LoadIcon(g_hInst, MAKEINTRESOURCE(IDI_ICON));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= 0;
	wcex.lpszClassName	= WindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON));
	

	if(RegisterClassEx(&wcex)==0)
		return false;

	// Retrieve the final client size of the window
	::GetClientRect( m_hWnd, &rc );
	m_nViewX		= rc.left;
	m_nViewY		= rc.top;
	m_nViewWidth	= rc.right - rc.left;
	m_nViewHeight	= rc.bottom - rc.top;

	m_hWnd = CreateWindow(WindowClass, WindowTitle, WS_POPUPWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, Width, Height, NULL, NULL, g_hInst, this);

	if (!m_hWnd)
		return false;

	// Show the window
	ShowWindow(m_hWnd, SW_MAXIMIZE);

	// Success!!
	return true;
}

//-----------------------------------------------------------------------------
// Name : BeginGame ()
// Desc : Signals the beginning of the physical post-initialisation stage.
//		From here on, the game engine has control over processing.
//-----------------------------------------------------------------------------
int CGameApp::BeginGame()
{
	MSG		msg;

	// Start main loop
	while(true) 
	{
		// Did we recieve a message, or are we idling ?
		if ( PeekMessage(&msg, NULL, 0, 0, PM_REMOVE) ) 
		{
			if (msg.message == WM_QUIT) break;
			TranslateMessage( &msg );
			DispatchMessage ( &msg );
		} 
		else 
		{
			// Advance Game Frame.
			FrameAdvance();

		} // End If messages waiting
	
	} // Until quit message is receieved

	return 0;
}

//-----------------------------------------------------------------------------
// Name : ShutDown ()
// Desc : Shuts down the game engine, and frees up all resources.
//-----------------------------------------------------------------------------
bool CGameApp::ShutDown()
{
	// Release any previously built objects
	ReleaseObjects ( );
	
	// Destroy menu, it may not be attached
	if ( m_hMenu ) DestroyMenu( m_hMenu );
	m_hMenu		 = NULL;

	// Destroy the render window
	SetMenu( m_hWnd, NULL );
	if ( m_hWnd ) DestroyWindow( m_hWnd );
	m_hWnd		  = NULL;
	
	// Shutdown Success
	return true;
}

//-----------------------------------------------------------------------------
// Name : StaticWndProc () (Static Callback)
// Desc : This is the main messge pump for ALL display devices, it captures
//		the appropriate messages, and routes them through to the application
//		class for which it was intended, therefore giving full class access.
// Note : It is VITALLY important that you should pass your 'this' pointer to
//		the lpParam parameter of the CreateWindow function if you wish to be
//		able to pass messages back to that app object.
//-----------------------------------------------------------------------------
LRESULT CALLBACK CGameApp::StaticWndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	// If this is a create message, trap the 'this' pointer passed in and store it within the window.
	if ( Message == WM_CREATE ) SetWindowLong( hWnd, GWL_USERDATA, (LONG)((CREATESTRUCT FAR *)lParam)->lpCreateParams);

	// Obtain the correct destination for this message
	CGameApp *Destination = (CGameApp*)GetWindowLong( hWnd, GWL_USERDATA );
	
	// If the hWnd has a related class, pass it through
	if (Destination) return Destination->DisplayWndProc( hWnd, Message, wParam, lParam );
	
	// No destination found, defer to system...
	return DefWindowProc( hWnd, Message, wParam, lParam );
}

//-----------------------------------------------------------------------------
// Name : DisplayWndProc ()
// Desc : The display devices internal WndProc function. All messages being
//		passed to this function are relative to the window it owns.
//-----------------------------------------------------------------------------
LRESULT CGameApp::DisplayWndProc( HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam )
{
	static UINT			fTimer;	

	// Determine message type
	switch (Message)
	{
		case WM_CREATE:
			break;
		
		case WM_CLOSE:
			PostQuitMessage(0);
			break;
		
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		
		case WM_SIZE:
			if ( wParam == SIZE_MINIMIZED )
			{
				// App is inactive
				m_bActive = false;
			
			} // App has been minimized
			else
			{
				// App is active
				m_bActive = true;

				// Store new viewport sizes
				m_nViewWidth  = LOWORD( lParam );
				m_nViewHeight = HIWORD( lParam );
		
			
			} // End if !Minimized

			break;

		case WM_LBUTTONDOWN:
			// Capture the mouse
			SetCapture( m_hWnd );
			GetCursorPos( &m_OldCursorPos );
			break;

		case WM_LBUTTONUP:
			// Release the mouse
			ReleaseCapture( );
			break;

		case WM_KEYDOWN:
			switch(wParam)
			{
			case VK_ESCAPE:
				PostQuitMessage(0);
				break;
			
			}
			break;

		//case WM_TIMER:
		//	switch (wParam)
		//	{
		//	}
		//	break;

		case WM_COMMAND:
			break;

		default:
			return DefWindowProc(hWnd, Message, wParam, lParam);

	} // End Message Switch
	
	return 0;
}

void CGameApp::Logic()
{
	if (score % 100 == 0 || score2 %100 == 0) {
		shield->avaiable = 500;
	}
	shield->shieldAvaiable();
	if (invincibleTime != 0) {
		invincibleTime--;
	}

	if (score % 50 == 0 || score2 % 50 == 0) {
		coin->avaiable = 500;
	}
	coin->coinAvaiable();
}

//-----------------------------------------------------------------------------
// Name : BuildObjects ()
// Desc : Build our demonstration meshes, and the objects that instance them
//-----------------------------------------------------------------------------
bool CGameApp::BuildObjects()
{

	m_pBBuffer = new BackBuffer(m_hWnd, m_nViewWidth, m_nViewHeight); //importantthingy

	m_pPlayer = new CPlayer(m_pBBuffer, "data/player.bmp", 0);

	m_pPlayerTwo = new CPlayer(m_pBBuffer, "data/playeTwo.bmp", 50);

	shield = new Shield(m_pBBuffer);

	coin = new Coin(m_pBBuffer);

	m_Street = new Street(m_pBBuffer);

	m_Railroad = new Railroad(m_pBBuffer);

	for (int i = 0; i < NUMBER_OF_CAR; i++)
	{
		m_Car[i] = new Car(m_pBBuffer);
	}

	for (int i = 0; i < NUMBER_OF_TRAIN; i++)
	{
		m_Train[i] = new Train(m_pBBuffer);
	}
	
	if(!m_imgBackground.LoadBitmapFromFile("data/background2.bmp", GetDC(m_hWnd)))
		return false;

	m_imgBackground.SetFilter(new CBoxFilter());
	m_imgBackground.Resample(m_nViewWidth, m_nViewHeight);

	// Success!
	return true;
}

//-----------------------------------------------------------------------------
// Name : SetupGameState ()
// Desc : Sets up all the initial states required by the game.
//-----------------------------------------------------------------------------
void CGameApp::SetupGameState()
{
    m_Street->Position() = Vec2(680,600);
	m_Railroad->Position() = Vec2(680,200);
	m_pPlayer->Position() = Vec2(500,800);
	m_pPlayerTwo->Position() = Vec2(700, 800);

	for (int i = 0; i < NUMBER_OF_CAR; i++)
	{
		
		m_Car[i]->Position().y = m_Street->Position().y - 120;
		m_Car[i]->Position().x = m_Car[i - 1]->Position().x +300;
		
	}

	for (int i = 0; i < NUMBER_OF_TRAIN; i++)
	{
		m_Train[i]->Position().y = m_Railroad->Position().y - 120;
		m_Train[i]->Position().x = m_Train[i - 1]->Position().x + 120;
	}
}

//-----------------------------------------------------------------------------
// Name : ReleaseObjects ()
// Desc : Releases our objects and their associated memory so that we can
//		rebuild them, if required, during our applications life-time.
//-----------------------------------------------------------------------------
void CGameApp::ReleaseObjects( )
{
	if(m_pPlayer != NULL)
	{
		delete m_pPlayer;
		m_pPlayer = NULL;
	}

	if (m_pPlayerTwo != NULL)
	{
		delete m_pPlayerTwo;
		m_pPlayerTwo = NULL;
	}

	if (shield != NULL) {
		delete shield;
		shield = NULL;
	}

	if (coin != NULL) {
		delete coin;
		coin = NULL;
	}
	
	if(m_pBBuffer != NULL)
	{
		delete m_pBBuffer;
		m_pBBuffer = NULL;
	}
	if (m_Street != NULL)
	{
		delete m_Street;
		m_Street = NULL;
	}
	if (m_Railroad != NULL)
	{
		delete m_Railroad;
		m_Railroad = NULL;
	}
	for (int i = 0; i < NUMBER_OF_CAR; i++)
	{

		if (m_Car[i] != NULL)
		{
			delete m_Car[i];
			m_Car[i] = NULL;
		}
	}
	for (int i = 0; i < NUMBER_OF_TRAIN; i++)
	{

		if (m_Train[i] != NULL)
		{
			delete m_Train[i];
			m_Train[i] = NULL;
		}
	}
	
}

//-----------------------------------------------------------------------------
// Name : FrameAdvance () (Private)
// Desc : Called to signal that we are now rendering the next frame.
//-----------------------------------------------------------------------------
void CGameApp::FrameAdvance()
{

	// Poll & Process input devices
	ProcessInput();

	Logic();

	// Animate the game objects
	AnimateObjects();

	// Drawing the game objects
	DrawObjects();
}

//-----------------------------------------------------------------------------
// Name : ProcessInput () (Private)
// Desc : Simply polls the input devices and performs basic input operations
//-----------------------------------------------------------------------------
void CGameApp::ProcessInput( )
{
	static UCHAR pKeyBuffer[ 256 ];
	ULONG		Direction = 0, Direction2 = 0;
	POINT		CursorPos;
	float		X = 0.0f, Y = 0.0f;

	// Retrieve keyboard state
	if ( !GetKeyboardState( pKeyBuffer ) ) return;

	// Check the relevant keys

	if (pKeyBuffer[VK_UP] & 0xF0) { Direction |= CPlayer::DIR_FORWARD; 		score++;}
	if (pKeyBuffer[VK_DOWN] & 0xF0) Direction |= CPlayer::DIR_BACKWARD;
	if (pKeyBuffer[VK_LEFT] & 0xF0) Direction |= CPlayer::DIR_LEFT;
	if (pKeyBuffer[VK_RIGHT] & 0xF0) Direction |= CPlayer::DIR_RIGHT;

	if (pKeyBuffer['W'] & 0xF0) {
		Direction2 |= CPlayer::DIR_FORWARD;	score2++;
	}
	if (pKeyBuffer['S'] & 0xF0) Direction2 |= CPlayer::DIR_BACKWARD;
	if (pKeyBuffer['A'] & 0xF0) Direction2 |= CPlayer::DIR_LEFT;
	if (pKeyBuffer['D'] & 0xF0) Direction2 |= CPlayer::DIR_RIGHT;
	

	m_pPlayer->Move(Direction);
	m_pPlayerTwo->Move(Direction2);

	Edge(*m_pPlayer);
	Edge(*m_pPlayerTwo);

	UpdateGame(*m_pPlayer, *m_Street, *m_Railroad);
	UpdateGame(*m_pPlayerTwo, *m_Street, *m_Railroad);


	// Now process the mouse (if the button is pressed)
	if ( GetCapture() == m_hWnd )
	{
		// Hide the mouse pointer
		SetCursor( NULL );

		// Retrieve the cursor position
		GetCursorPos( &CursorPos );

		// Reset our cursor position so we can keep going forever :)
		SetCursorPos( m_OldCursorPos.x, m_OldCursorPos.y );

	} // End if Captured
}

//-----------------------------------------------------------------------------
// Name : AnimateObjects () (Private)
// Desc : Animates the objects we currently have loaded.
//-----------------------------------------------------------------------------
void CGameApp::AnimateObjects()
{
	static UINT			fTimer;

	m_pPlayer->Update(m_Timer.GetTimeElapsed());
	m_pPlayerTwo->Update(m_Timer.GetTimeElapsed());
	m_Street->Update(m_Timer.GetTimeElapsed());
	m_Railroad->Update(m_Timer.GetTimeElapsed());

	for (int i = 0; i < NUMBER_OF_CAR; i++)
	{
		m_Car[i]->Update(m_Timer.GetTimeElapsed());
	}
	for (int i = 0; i < NUMBER_OF_TRAIN; i++)
	{
		m_Train[i]->Update(m_Timer.GetTimeElapsed());
	}
	
	Car_Street();

}


//-----------------------------------------------------------------------------
// Name : DrawObjects () (Private)
// Desc : Draws the game objects
//-----------------------------------------------------------------------------
void CGameApp::DrawObjects()
{
	USHORT			Width = (int)GetSystemMetrics(SM_CXSCREEN);
	USHORT			Height = (int)GetSystemMetrics(SM_CYSCREEN);

	m_pBBuffer->reset();
	m_imgBackground.Paint(m_pBBuffer->getDC(), 0, 0);
	m_Street->Draw();
	m_Railroad->Draw();
	shield->Draw();
	coin->Draw();
	
	for (int i = 0; i < NUMBER_OF_CAR; i++)
	{
		m_Car[i]->Draw();
	}
	for (int i = 0; i < NUMBER_OF_TRAIN; i++)
	{
		m_Train[i]->Draw();
	}
	
	m_pPlayer->Draw();
	m_pPlayerTwo->Draw();
	Draw_statusP1();
	Draw_statusP2();
	Draw_FPS();
	m_pBBuffer->present();
	
}
void CGameApp::Edge(CPlayer& player)
{
	if (player.Position().x <= 50)
	{
		player.Position().x = 50;
		player.Velocity().x = 0;
		player.Position().x = 51;
	}
	else if (player.Position().x >= m_nViewWidth-50)
	{
		player.Position().x = m_nViewWidth-50;
		player.Velocity().x = 0;
		player.Position().x = m_nViewWidth - 51;
	}
	else if (player.Position().y <= 100)
	{
		player.Position().y = 100;
		player.Velocity().y = 0;
		player.Position().y = 101;
	}
}

void CGameApp::Car_Street()
{
	for (int i = 0; i < NUMBER_OF_CAR/2; i++)
	{
		m_Car[i]->Velocity() = Vec2(-500 + (-(score * 2)), 0);
		m_Car[i]->Position().y = m_Street->Position().y - 40;
	}
	for (int i = NUMBER_OF_CAR / 2; i < NUMBER_OF_CAR; i++)
	{
		m_Car[i]->Position().y = m_Street->Position().y + 40;
		m_Car[i]->Velocity()= Vec2(500 + (score * 2), 0);
	}

	for (int i = 0; i < NUMBER_OF_TRAIN / 2; i++)
	{
		m_Train[i]->Velocity() = Vec2(-500 + (-(score * 2)), 0);
		m_Train[i]->Position().y = m_Railroad->Position().y - 85;
	}
	for (int i = NUMBER_OF_TRAIN / 2; i < NUMBER_OF_TRAIN; i++)
	{
		m_Train[i]->Position().y = m_Railroad->Position().y + 80;
		m_Train[i]->Velocity() = Vec2(500 + (score * 2), 0);
	}
}
void CGameApp::UpdateGame(CPlayer& player, Street& street, Railroad& raiload)
{	
	if (player.Position().y <= 600)
	{
		street.Velocity().y = 50;
		raiload.Velocity().y = 50;
	}

	else
	{
		street.Velocity().y = 10;
		raiload.Velocity().y = 10;
	}

	if (CPlayer::DIR_FORWARD)
	{
		//score++;
		//player.Velocity().y = street.Velocity().y;
	}
	else
		player.Velocity().y = 0;
	
	if (m_pPlayer->Position().y > 1000)
	{
		GameOver("data/Player2Win.bmp");
	}
	if (m_pPlayerTwo->Position().y > 1000)
	{
		GameOver("data/Player1Win.bmp");
	}

	if (m_pPlayer->getLives().size() == 0)
	{
		GameOver("data/Player2Win.bmp");
	}
	if (m_pPlayerTwo->getLives().size() == 0)
	{
		GameOver("data/Player1Win.bmp");
	}

	for (int i = 0; i < NUMBER_OF_TRAIN; i++)
	{
		collision(m_pPlayer, m_Train[i]);
	}
	for (int i = 0; i < NUMBER_OF_CAR; i++)
	{
		collision2(m_pPlayer,m_Car[i]);
	}
	collision3(m_pPlayer, shield);
	collision4(m_pPlayer, coin);

	for (int i = 0; i < NUMBER_OF_TRAIN; i++)
	{
		collision(m_pPlayerTwo, m_Train[i]);
	}
	for (int i = 0; i < NUMBER_OF_CAR; i++)
	{
		collision2(m_pPlayerTwo, m_Car[i]);
	}
	collision3(m_pPlayerTwo, shield);
	collision4(m_pPlayerTwo, coin);
}
void CGameApp::collision(CPlayer* object1,Train* object2)
{
	if (invincibleTime == 0) {
		if (!(object1->Position().y - object1->getSprite()->height() / 2 > object2->Position().y + object2->getSprite()->height() / 2
			|| object1->Position().y + object1->getSprite()->height() / 2 < object2->Position().y - object2->getSprite()->height() / 2
			|| object1->Position().x - object1->getSprite()->width() / 2 > object2->Position().x
			|| object1->Position().x + object1->getSprite()->width() / 2 < object2->Position().x))
		{
			object1->Explode();
			object2->Velocity() = Vec2(0, 0);
			object1->Position().y = object1->Position().y + 100;
		}
	}
}
void CGameApp::collision2(CPlayer* object1,Car* object2)
{
	if (invincibleTime == 0) {
		if (!(object1->Position().y - object1->getSprite()->height() / 2 > object2->Position().y + object2->getSprite()->height() / 2
			|| object1->Position().y + object1->getSprite()->height() / 2 < object2->Position().y - object2->getSprite()->height() / 2
			|| object1->Position().x - object1->getSprite()->width() / 2 > object2->Position().x
			|| object1->Position().x + object1->getSprite()->width() / 2 < object2->Position().x))
		{
			object1->Explode();
			object2->Velocity() = Vec2(0, 0);
			object1->Position().y = object1->Position().y + 100;
		}
	}
}

void CGameApp::collision3(CPlayer * object1, Shield * object2)
{

	if (!(object1->Position().y - object1->getSprite()->height() / 2 > object2->Position().y + object2->getSprite()->height() / 2
		|| object1->Position().y + object1->getSprite()->height() / 2 < object2->Position().y - object2->getSprite()->height() / 2
		|| object1->Position().x - object1->getSprite()->width() / 2 > object2->Position().x
		|| object1->Position().x + object1->getSprite()->width() / 2 < object2->Position().x))
	{
		shield->avaiable = 0;
		invincibleTime = 300;
	}

}

void CGameApp::collision4(CPlayer * object1, Coin * object2)
{
	if (!(object1->Position().y - object1->getSprite()->height() / 2 > object2->Position().y + object2->getSprite()->height() / 2
		|| object1->Position().y + object1->getSprite()->height() / 2 < object2->Position().y - object2->getSprite()->height() / 2
		|| object1->Position().x - object1->getSprite()->width() / 2 > object2->Position().x
		|| object1->Position().x + object1->getSprite()->width() / 2 < object2->Position().x))
	{
		coin->avaiable = 0;
		score += 100;
	}
}

void CGameApp::Draw_statusP1()
{
	USHORT			Width = (int)GetSystemMetrics(SM_CXSCREEN);
	USHORT			Height = (int)GetSystemMetrics(SM_CYSCREEN);

	sprintf(Score, _T(" Score P1 : %d  "), score);
	RECT Frame = { Width - Width / 10, 10, Width, 50 };
	DrawText(m_pBBuffer->getDC(), Score, -1, &Frame, DT_CENTER);
}

void CGameApp::Draw_statusP2()
{
	USHORT			Width = (int)GetSystemMetrics(SM_CXSCREEN);
	USHORT			Height = (int)GetSystemMetrics(SM_CYSCREEN);

	sprintf(Score2, _T(" Score P2 : %d  "), score2);
	RECT Frame = { Width - Width / 10, 30, Width, 50 };
	DrawText(m_pBBuffer->getDC(), Score2, -1, &Frame, DT_CENTER);
}

void CGameApp::Draw_FPS()
{
	static TCHAR FrameRate[50];

	// Advance the timer
	m_Timer.Tick();

	// Skip if app is inactive
	if (!m_bActive) return;

	// Get / Display the framerate

	m_LastFrameRate = m_Timer.GetFrameRate(FrameRate, 50);

	USHORT			Width = (int)GetSystemMetrics(SM_CXSCREEN);
	USHORT			Height = (int)GetSystemMetrics(SM_CYSCREEN);

	sprintf(Score, _T(" %s  "), FrameRate);
	RECT Frame = { 10, 10, Width, 50 };
	DrawText(m_pBBuffer->getDC(), Score, -1, &Frame, DT_CENTER);
}

void CGameApp::GameOver(const char * imagePath)
{
	m_imgBackground.LoadBitmapFromFile(imagePath, GetDC(m_hWnd));
	m_imgBackground.Resample(GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN));
	m_pPlayer->getSprite()->~Sprite();
	m_pPlayerTwo->getSprite()->~Sprite();
	m_Street->getSprite()->~Sprite();

	for (int i = 0; i < NUMBER_OF_CAR; i++)
	{
		m_Car[i]->getSprite()->~Sprite();
	}

	for (int i = 0; i < NUMBER_OF_TRAIN; i++)
	{
		m_Train[i]->getSprite()->~Sprite();
	}

	m_Railroad->getSprite()->~Sprite();
	
}

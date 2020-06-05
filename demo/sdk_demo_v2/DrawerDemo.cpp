#include "DrawerDemo.h"

DrawerDemo::~DrawerDemo()
{
	OutputDebugString(L"WTTF!!!\n");
}

void DrawerDemo::Init()
{
	ImgPtr img(new sf::Image());
	if (img->loadFromFile("C:\\Lenna.png")) {
		OutputDebugString(L"image loaded successfully\n");
	}
	else {
		OutputDebugString(L"failed to load image\n");
		img->create(512, 512, sf::Color::Green);
	}
	m_img = img;
	m_txt.loadFromImage(*m_img);
}

void DrawerDemo::Draw(sf::RenderWindow* window)
{
	//OutputDebugString(L"draw started\n");

	m_spr.setTexture(m_txt, true);

	window->draw(m_spr);
}

void DrawerDemo::PutFrame(const ImgConstPtr& frame, uint32_t ts_ms)
{
	//OutputDebugString(L"Received new frame\n");
	//m_img = frame;
	//m_txt.update(*m_img);
}

void DrawerDemo::PutLayout(const Layout& layout)
{

}
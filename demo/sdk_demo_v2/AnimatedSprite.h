#pragma once
#include<SFML/Graphics.hpp>
#include "SceneElements.h"

struct SpriteMetaData
{
	int totalNum;
	int colNum;
	int rowNum;
	sf::Vector2u last;
};

class AnimatedSprite : public IFlyingObject
{
public:
	AnimatedSprite(
		const Scene::WeakPtr& scene,
		std::string spriteFile,
		sf::IntRect spriteRect,
		std::string splashFile,
		sf::Vector2f scaleSplash,
		float baseRotation = 0,
		float speed = 5);

	void nextSprite();

	void OnCollision(bool* destroy) override;
	sf::FloatRect GetGlobalBounds() const override;
	void MoveBySpeed() override;
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	Scene::WeakPtr m_scene;
	sf::Texture _texture;
	sf::Sprite _sprite;
	sf::IntRect _rect;
	SpriteMetaData _meta;
	int _current;
	float _baseRotation;
	float _speed;
	std::string _splashFile;
	sf::Vector2f _scaleSplash;

	int getSumPixels(sf::Image, sf::IntRect);
	SpriteMetaData getSpriteMetaData(sf::Texture, int, int);
};

class AnimatedSpriteSplash : public ISplashObject {
public:
	using Ptr = std::shared_ptr<AnimatedSpriteSplash>;

	AnimatedSpriteSplash(const sf::Vector2f& pos, std::string fileName);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

private:
	sf::Sprite m_shape;
	sf::Texture m_texture;
};

class AnimatedEffect : public IAnimatedObject
{
public:
	using Ptr = std::shared_ptr<AnimatedEffect>;
	AnimatedEffect(const sf::Vector2f& pos, std::string fileName, sf::IntRect, int from, int to);

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	void UpdateObject() override;
private:
	sf::Sprite m_shape;
	sf::Texture m_texture;
	sf::IntRect m_rect;
	SpriteMetaData m_meta;

	int getSumPixels(sf::Image, sf::IntRect);
	SpriteMetaData getSpriteMetaData();
};
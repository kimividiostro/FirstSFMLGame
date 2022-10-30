#include "Animation.hpp"

Animation::Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime) {
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	totalTime = 0.0f;

	auto textureSize = texture->getSize();
	textureRect.width = textureSize.x / float(this->imageCount.x);
	textureRect.height = textureSize.y / float(this->imageCount.y);
}

Animation::~Animation() {}

void Animation::Update(int row, float deltaTime)
{
	currentImage.y = row;
	totalTime += deltaTime;

	if (totalTime >= switchTime) {
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x) currentImage.x = 0;
	}

	textureRect.left = currentImage.x * textureRect.width;
	textureRect.top = currentImage.y * textureRect.height;
}

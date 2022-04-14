//setup window
	sf::Vector2i screenDimensions(640, 480);
	sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Test window");
	window.setFramerateLimit(60);
	
	//load texture (spritesheet)
	sf::Texture texture;
	if (!texture.loadFromFile("assets/characters/Knight/knight_outline.png"))
	{
		cerr << "\nFailed to load spritesheet!" << endl;
		return 1;
	}
	
	//set up animations for all four directions
    
	// set up the animations for all four directions (set spritesheet and push frames)
	Animation idleAnimation;
	idleAnimation.setSpriteSheet(texture);
	idleAnimation.addFrame(sf::IntRect(72, 0, 72, 72));

	Animation walkingAnimationDown;
	walkingAnimationDown.setSpriteSheet(texture);
	walkingAnimationDown.addFrame(sf::IntRect(0, 0, 72, 72));
	walkingAnimationDown.addFrame(sf::IntRect(72, 0, 72, 72));
	walkingAnimationDown.addFrame(sf::IntRect(144, 0, 72, 72));
	walkingAnimationDown.addFrame(sf::IntRect(0, 0, 72, 72));

	Animation walkingAnimationLeft;
	walkingAnimationLeft.setSpriteSheet(texture);
	walkingAnimationLeft.addFrame(sf::IntRect(576, 216, 72, 72));
	walkingAnimationLeft.addFrame(sf::IntRect(504, 216, 72, 72));
	walkingAnimationLeft.addFrame(sf::IntRect(432, 216, 72, 72));
	walkingAnimationLeft.addFrame(sf::IntRect(576, 216, 72, 72));


	Animation walkingAnimationRight;
	walkingAnimationRight.setSpriteSheet(texture);
	walkingAnimationRight.addFrame(sf::IntRect(0, 0, 72, 72));
	walkingAnimationRight.addFrame(sf::IntRect(72, 0, 72, 72));
	walkingAnimationRight.addFrame(sf::IntRect(144, 0, 72, 72));
	walkingAnimationRight.addFrame(sf::IntRect(0, 0, 72, 72));

	Animation walkingAnimationUp;
	walkingAnimationUp.setSpriteSheet(texture);
	walkingAnimationUp.addFrame(sf::IntRect(0, 0, 72, 72));
	walkingAnimationUp.addFrame(sf::IntRect(72, 0, 72, 72));
	walkingAnimationUp.addFrame(sf::IntRect(144, 0, 72, 72));
	walkingAnimationUp.addFrame(sf::IntRect(0, 0, 72, 72));

	Animation attackAnimationRight;
	attackAnimationRight.setSpriteSheet(texture);
	attackAnimationRight.addFrame(sf::IntRect(0, 72, 72, 72));
	attackAnimationRight.addFrame(sf::IntRect(72, 72, 72, 72));
	attackAnimationRight.addFrame(sf::IntRect(144, 72, 72, 72));
	attackAnimationRight.addFrame(sf::IntRect(0, 72, 72, 72));

	Animation attackAnimationLeft;
	attackAnimationLeft.setSpriteSheet(texture);
	attackAnimationLeft.addFrame(sf::IntRect(576, 288, 72, 72));
	attackAnimationLeft.addFrame(sf::IntRect(504, 288, 72, 72));
	attackAnimationLeft.addFrame(sf::IntRect(432, 288, 72, 72));
	attackAnimationLeft.addFrame(sf::IntRect(576, 288, 72, 72));

	Animation deathAnimationRight;
	deathAnimationRight.setSpriteSheet(texture);
	deathAnimationRight.addFrame(sf::IntRect(576, 72, 72, 72));
	//deathAnimationRight.addFrame(sf::IntRect(576, 144, 72, 72)); //with sword
	//deathAnimationRight.addFrame(sf::IntRect(576, 216, 72, 72)); //with bazzoka ?

	Animation deathAnimationLeft;
	deathAnimationLeft.setSpriteSheet(texture);
	deathAnimationLeft.addFrame(sf::IntRect(0, 216, 72, 72));
	//deathAnimationLeft.addFrame(sf::IntRect(0, 288, 72, 72)); // with sword
	//deathAnimationLeft.addFrame(sf::IntRect(0, 360, 72, 72)); // with bazzoka ?

	Animation* currentAnimation = &idleAnimation;

	// set up AnimatedSprite
	AnimatedSprite animatedSprite(sf::seconds(0.2), true, false);
	AnimatedSprite monsterSprite(sf::seconds(0.2), true, false);
	animatedSprite.setPosition(sf::Vector2f(screenDimensions / 2));
	monsterSprite.setPosition(sf::Vector2f(screenDimensions / 2));

	sf::Clock frameClock;

	float speed = 80.f;
	bool noKeyWasPressed = true;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
				window.close();
		}

		sf::Time frameTime = frameClock.restart();

		// if a key was pressed set the correct animation and move correctly
		sf::Vector2f movement(0.f, 0.f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			currentAnimation = &walkingAnimationUp;
			movement.y -= speed;
			noKeyWasPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			currentAnimation = &walkingAnimationDown;
			movement.y += speed;
			noKeyWasPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			currentAnimation = &walkingAnimationLeft;
			movement.x -= speed;
			noKeyWasPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			currentAnimation = &walkingAnimationRight;
			movement.x += speed;
			noKeyWasPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			if(currentAnimation == &walkingAnimationRight)
				currentAnimation = &attackAnimationRight;
			if (currentAnimation == &walkingAnimationLeft)
				currentAnimation = &attackAnimationLeft;

			noKeyWasPressed = false;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			if (currentAnimation == &walkingAnimationRight)
				currentAnimation = &deathAnimationRight;
			if (currentAnimation == &walkingAnimationLeft)
				currentAnimation = &deathAnimationLeft;

			noKeyWasPressed = false;
		}
		monsterSprite.play(*currentAnimation);
		animatedSprite.play(*currentAnimation);
		animatedSprite.move(movement * frameTime.asSeconds());

		// if no key was pressed stop the animation
		if (noKeyWasPressed)
		{
			animatedSprite.stop();
		}
		noKeyWasPressed = true;

		// update AnimatedSprite
		animatedSprite.update(frameTime);
		monsterSprite.update(frameTime);

		// draw
		window.clear();
		window.draw(animatedSprite);
		window.draw(monsterSprite);
		window.display();
	}
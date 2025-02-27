#ifndef GAMEMANGER_HPP
#define GAMEMANGER_HPP 

#include "MyContext.hpp"
#include "Util/GameObject.hpp"
#include "Util/Renderer.hpp"
#include "Util/BGM.hpp"
#include "Util/Text.hpp"
#include "ImageObject.hpp"
#include "TextObject.hpp"
#include "Mario.hpp"

#include <memory>

class GameManager
{

public:
	GameManager() = default;
	~GameManager() = default;

	void init() noexcept;

	void Update(std::shared_ptr<Core::Context>&) noexcept;

	void End() noexcept;

	inline bool isEnd() const noexcept { return endstate; }

private:
	Util::Renderer m_Root;
	std::shared_ptr<Util::BGM> bgm;
	std::shared_ptr<TextObject> text;
	std::shared_ptr<ImageObject> background;

	std::shared_ptr<Mario> mario;
	

	bool endstate = false;
};


#endif // !GAMEMANGER_HPP



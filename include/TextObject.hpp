#ifndef TEXTOBJECT_HPP
#define TEXTOBJECT_HPP

#include "Object.hpp"
#include "Util/Color.hpp"
#include "Util/Text.hpp"

class TextObject : public Object {

public:

	TextObject(
		const std::string& font, int size, const std::string& text,
		const Util::Color& color,
		const float 	zIndex,
		const glm::vec2& pivot = { 0, 0 },
		const bool 	visible = true,
		const std::vector< std::shared_ptr< GameObject > >& children = std::vector<std::shared_ptr<GameObject>>())
		: Object(std::make_unique<Util::Text>(font, size, text, color),zIndex,pivot,visible,children) {
		
	}

	TextObject(
		const std::shared_ptr< Core::Drawable >& drawable,
		const float 	zIndex,
		const glm::vec2& pivot = { 0, 0 },
		const bool 	visible = true,
		const std::vector< std::shared_ptr< GameObject > >& children = std::vector<std::shared_ptr<GameObject>>()
	) :Object(drawable, zIndex, pivot, visible, children) {}

	TextObject(const TextObject& other) = default;

	TextObject(TextObject&& other) = default;

	TextObject() = default;

	inline void setText(const std::string& text) noexcept;

	inline glm::vec2&& GetSize() const noexcept override {
		return std::dynamic_pointer_cast<Util::Text>(m_Drawable)->GetSize();
	}

};

#endif // !BackgroundObject

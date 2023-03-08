#include "Span.hpp"

const char* Span::ContentFullException::what() const _NOEXCEPT {
    return "Span is already full.";
}

const char* Span::NotEnoughContentNumException::what() const _NOEXCEPT {
    return "Span doesn't have enough content to see distance.";
}
#ifndef STACK_HPP
#define STACK_HPP

#include <deque>
#include <cassert>

template<class T, class Container = std::deque<T>>
class stack {
public:
    using container_type = Container;
    using value_type = typename Container::value_type;
    using size_type = typename Container::size_type;
    using reference = typename Container::reference;
    using const_reference = typename Container::const_reference;

protected:
    Container c;

public:
    stack() = default;
    explicit stack(const Container& cont) : c(cont) {}
    explicit stack(Container&& cont) : c(std::move(cont)) {}
    stack(const stack& other) = default;
    stack(stack&& other) noexcept = default;

    ~stack() = default;

    stack& operator=(const stack& other) = default;
    stack& operator=(stack&& other) noexcept = default;

    reference top() {
        assert(!c.empty());
        return c.back();
    }

    const_reference top() const {
        assert(!c.empty());
        return c.back();
    }

    bool empty() const noexcept {
        return c.empty();
    }

    size_type size() const noexcept {
        return c.size();
    }

    void push(const value_type& value) {
        c.push_back(value);
    }

    void push(value_type&& value) {
        c.push_back(std::move(value));
    }

    template<class... Args>
    void emplace(Args&&... args) {
        c.emplace_back(std::forward<Args>(args)...);
    }

    void pop() {
        assert(!c.empty());
        c.pop_back();
    }

    void swap(stack& other) noexcept {
        std::swap(c, other.c);
    }

    friend bool operator==(const stack& lhs, const stack& rhs) {
        return lhs.c == rhs.c;
    }

    friend bool operator!=(const stack& lhs, const stack& rhs) {
        return lhs.c != rhs.c;
    }

    friend bool operator<(const stack& lhs, const stack& rhs) {
        return lhs.c < rhs.c;
    }

    friend bool operator<=(const stack& lhs, const stack& rhs) {
        return lhs.c <= rhs.c;
    }

    friend bool operator>(const stack& lhs, const stack& rhs) {
        return lhs.c > rhs.c;
    }

    friend bool operator>=(const stack& lhs, const stack& rhs) {
        return lhs.c >= rhs.c;
    }

    friend void swap(stack& lhs, stack& rhs) noexcept {
        lhs.swap(rhs);
    }
};

#endif 

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:41:58 by mbenkhat          #+#    #+#             */
/*   Updated: 2022/12/03 17:03:08 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
 
#include <vector>
#include <iostream>
#include <memory>

namespace ft
{
template <typename container>
class Iterator
{
public:
	// constructors
	Iterator();
	Iterator(const Iterator &other);
	Iterator & operator=(Iterator & other);
	
	
};

template <class T, class Alloc = std::allocator<T> >
class vector
{  
public:
	typedef T										value_type;
	typedef Alloc									allocator_type;
	typedef typename allocator_type::size_type		size_type;
	typedef typename allocator_type::difference_type	difference_type;
	typedef value_type&								reference;
	typedef const value_type&						const_reference;
	typedef typename allocator_type::pointer		pointer;
	typedef typename allocator_type::const_pointer	const_pointer;

	// consturctors
	vector()
	:_alloc(), _size(0), _capacity(0)
	{
	};
	explicit vector( const allocator_type& alloc )
	:_alloc(alloc), _size(0), _capacity(0)
	{
	};

	explicit vector(size_type count, const value_type& value = value_type(), const  allocator_type &alloc = allocator_type())
	:_alloc(alloc), _size(count), _capacity(count)
	{
		_data = _alloc.allocate(count);
		for (int i = 0; i < count; i++)
		{
			_alloc.construct(_data + i, value);
		}
		
	}

	// template <class InputIterator> 
	//vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
	vector( const vector& other )
	:_alloc(other._alloc), _size(other._size), _capacity(other._capacity)
	{
		
	}

	// Destructor
	~vector(){
		for (int i = 0; i < _size; i++)
		{
			_alloc.destroy(_data + i);
		}
	};

	vector& operator=( const vector& other )
	{
		this->_alloc = other._alloc;
		this->_data = other._data;
		this->_size = other._size;
		this->_capacity = other._capacity;
		return *this;
	}

	// template <class InputIterator>  void assign (InputIterator first, InputIterator last);
	void assign(size_type count, const value_type& val)
	{
		if (count > _capacity)
		{
			for (size_type i = 0; i < _size; i++)
				_alloc.destroy(_data + i);
			_alloc.deallocate(_data, _size);
			_data = _alloc.allocate(count);
			for (size_type i = 0; i < count; i++)
				_alloc.construct(_data + i, val);
		}
		else
		{
			for (size_type i = 0; i < count; i++)
			{
				_data[i] = val;
			}
			for (size_type i = count; i < _size; i++)
			{
				_alloc.destroy(_data + i);
			}		
		}
		_size = count;
		_capacity = count;
	}

	// Allocator
	allocator_type get_allocator() const
	{
		return _alloc;
	}
	
	// Element access
	reference at(size_type pos)
	{
		return _data[pos];
	}
	const_reference at( size_type pos ) const
	{
		return _data[pos];
	}
	reference operator[]( size_type pos )
	{
		return _data[pos];
	}
	const_reference operator[]( size_type pos ) const
	{
		return _data[pos];
	}
	reference front()
	{
		return _data[0];
	}
	const_reference front() const
	{
		return _data[0];
	}
	reference back()
	{
		return _data[_size - 1];
	}
	const_reference back() const
	{
		return _data[_size - 1];
	}
	value_type* data()
	{
		return _data;
	}
	const value_type* data() const
	{
		return _data;
	}

	// Iterators
	

	// Capacity
	bool empty() const
	{
		return (_size == 0);
	}
	size_type size() const
	{
		return _size;
	}
	size_type max_size() const
	{
		return _alloc.max_size();
	}
	void reserve( size_type new_cap )
	{
		if (new_cap > max_size())
		{
			throw std::length_error("Exception: lenght error");
		}
		if (new_cap > _capacity)
		{
			pointer tmp = _alloc.allocate(new_cap);
			for (int i = 0; i < _size; i++)
			{
				_alloc.construct(tmp + i, _data[i]);
			}
			for (int i = 0; i < _size; i++)
			{
				_alloc.destroy(_data + i);
			}
			_alloc.deallocate(_data, _capacity);
			_data = tmp;
			_capacity = new_cap;
		}
	}
	size_type capacity() const
	{
		return (_capacity);
	}


	// Modifiers
	void clear()
	{
		for (int i = 0; i < _size; i++)
		{
			_alloc.destroy(_data + i);
		}
		_size = 0;
	}
	// iterator insert(iterator position, const value_type& val);
	// void insert (iterator position, size_type n, const value_type& val);
	// template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);
	// iterator erase( iterator pos );
	// iterator erase( iterator first, iterator last );
	void push_back(const value_type& val)
	{
		if (_size == _capacity)
		{
			if (!_capacity)
			{
				_data = _alloc.allocate(1);
				_alloc.construct(_data, val);
				_capacity = 1;
				_size = 1;
			}
			else
			{
				pointer tmp;
				tmp = _alloc.allocate(_capacity * 2);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.construct(tmp + i, _data[i]);
				}
				_alloc.construct(tmp + _size, val);
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(_data + i);
				}
				_alloc.deallocate(_data, _size);
				_data = tmp;
				_capacity *= 2;
				_size ++;
			}
			return ;
		}
		_alloc.construct(_data + _size, val);
		_size++;
	}
	
	void pop_back()
	{
		_alloc.destroy(_data + _size - 1);
		_size--;
	}

	void resize(size_type count, value_type value = value_type())
	{
		if (count <= _capacity)
		{
			while (_size < count)
			{
				_alloc.construct(_data + _size, value);
				_size++;
			}
		}
		else if (count > _capacity)
		{
				pointer tmp;
				tmp = _alloc.allocate(count);
				for (size_type i = 0; i < count; i++)
				{
					if (i < _size)
						_alloc.construct(tmp + i, _data[i]);
					else
						_alloc.construct(tmp + i, value);
				}
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(_data + i);
				}
				_alloc.deallocate(_data, _size);
				_data = tmp;
				_capacity = count;
				_size = count;
		}
	}

	void swap( vector& other )
	{
		allocator_type	tmp_alloc = this->_alloc;
		pointer			tmp_data = this->_data;
		size_type		tmp_size = this->_size;
		size_type		tmp_capacity = this->_capacity;
		this->_alloc = other._alloc;
		this->_data = other._data;
		this->_size = other._size;
		this->_capacity = other._capacity;
		other._alloc = tmp_alloc;
		other._data = tmp_data;
		other._size = tmp_size;
		other._capacity = tmp_capacity;
	}
	

private:
	allocator_type	_alloc;
	pointer			_data;
	size_type		_size;
	size_type		_capacity;
};
}
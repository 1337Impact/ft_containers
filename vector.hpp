/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenkhat <mbenkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:41:58 by mbenkhat          #+#    #+#             */
/*   Updated: 2023/01/08 09:00:55 by mbenkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <memory>
#include <iterator>

namespace ft
{
template <typename T>
class VectorIterator
{
public:
	typedef T				value_type;
	typedef value_type*		pointer;
	typedef value_type&		reference;
	typedef std::ptrdiff_t difference_type;
private:
	pointer _data;
public:
	// constructors
	VectorIterator():_data(0){}
	VectorIterator(pointer data):_data(data){}
	VectorIterator(const VectorIterator &other):_data(other._data){}
	VectorIterator & operator=(const VectorIterator & other)
	{
		this->_data = other._data;
		return *this;
	}

	bool operator==(const VectorIterator & other)
	{
		return _data == other._data;
	}
	bool operator!=(const VectorIterator & other)
	{
		return _data != other._data;
	}
	reference operator*(void)
	{
		return (*_data);
	}
	pointer operator->()
	{
		return _data;
	}
	
	VectorIterator operator++ (int)
	{
		VectorIterator<value_type> tmp(*this);
		_data++;
		return (tmp);
	}
	VectorIterator operator++ (void)
	{
		++_data;
		return (*this);
	}
	VectorIterator operator-- (int)
	{
		VectorIterator<value_type> tmp(*this);
		_data--;
		return (tmp);
	}
	VectorIterator operator-- (void)
	{
		--_data;
		return (*this);
	}

	VectorIterator operator+( int nbr )
	{
		VectorIterator<value_type> tmp(_data + nbr);
		return tmp;
	}

	VectorIterator operator-( int nbr )
	{
		VectorIterator<value_type> tmp(_data - nbr);
		return tmp;
	}

	difference_type operator-(const VectorIterator &other)
	{
		return (this->_data - other._data);
	}

	bool operator < (const VectorIterator &obj)
	{
		return this->_data < obj._data;
	}
	bool operator > (const VectorIterator &obj)
	{
		return this->_data > obj._data;
	}
	bool operator <= (const VectorIterator &obj)
	{
		return this->_data <= obj._data;
	}
	bool operator >= (const VectorIterator &obj)
	{
		return this->_data >= obj._data;
	}
	VectorIterator operator+= (const int nbr)
	{
		this->_data += nbr;
		return (*this);
	} 
	VectorIterator operator-= (const int nbr)
	{
		this->_data -= nbr;
		return (*this);
	}
	value_type operator[] (const int nbr)
	{
		return (*(_data + nbr));
	}
	~VectorIterator(){}
};

template <class T, class Alloc = std::allocator<T> >
class vector
{  
public:
	typedef T										value_type;
	typedef Alloc									allocator_type;
	typedef value_type&								reference;
	typedef const value_type&						const_reference;
	typedef typename allocator_type::pointer		pointer;
	typedef typename allocator_type::const_pointer	const_pointer;
	typedef VectorIterator<value_type>				iterator;
	typedef	VectorIterator<value_type const>		const_iterator;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef typename allocator_type::difference_type	difference_type;
	typedef typename allocator_type::size_type		size_type;
	

	// consturctors
	vector()
	:_alloc(), _data(0), _size(0), _capacity(0)
	{
	};
	explicit vector( const allocator_type& alloc )
	:_alloc(alloc), _data(0), _size(0), _capacity(0)
	{
	};

	explicit vector(size_type count, const value_type& value = value_type(), const  allocator_type &alloc = allocator_type())
	:_alloc(alloc), _size(count), _capacity(count)
	{
		_data = _alloc.allocate(count);
		for (size_type i = 0; i < count; i++)
		{
			_alloc.construct(_data + i, value);
		}
	}

	template <class InputIterator> 
	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
	:_alloc(alloc), _size(0), _capacity(0), _data(0)
	{
		assign(first, last);
	}
	
	vector( const vector& other )
	:_alloc(other._alloc), _size(other._size), _capacity(other._capacity)
	{
		this->_data = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(_data + i, other._data[i]);
	}

	// Destructor
	~vector(){
		clear();
		_alloc.deallocate(_data, _capacity);
	};

	vector& operator=( const vector& other )
	{
		this->_alloc = other._alloc;
		this->_size = other._size;
		this->_capacity = other._capacity;
		this->_data = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; i++)
			_alloc.construct(_data + i, other._data[i]);
		return *this;
	}

	template <class InputIterator>
	void assign (InputIterator first, InputIterator last)
	{
		size_type count = last - first;
		if (count > _capacity)
		{
			clear();
			_alloc.deallocate(_data, _capacity);
			_data = _alloc.allocate(count);
			for (size_type i = 0; i < count; i++)
				_alloc.construct(_data + i, *(first + i));
			_capacity = count;
		}
		else
		{
			clear();
			for (size_type i = 0; i < count; i++)
			{
				*(_data + i) = *(first + i);
			}
		}
		_size = count;
	}
	
	void assign(size_type count, const value_type& val)
	{
		if (count > _capacity)
		{
			clear();
			_alloc.deallocate(_data, _size);
			_data = _alloc.allocate(count);
			for (size_type i = 0; i < count; i++)
				_alloc.construct(_data + i, val);
			_capacity = count;
		}
		else
		{
			clear();
			for (size_type i = 0; i < count; i++)
			{
				_data[i] = val;
			}
		}
		_size = count;
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
	pointer data()
	{
		return _data;
	}
	const_pointer data() const
	{
		return _data;
	}
	// Iterators
	iterator begin(){
		return iterator(_data);
	}
	const_iterator begin() const
	{
		return const_iterator(_data);
	}
	iterator end()
	{
		return iterator(_data + _size);
	}
	const_iterator end() const
	{
		return const_iterator(_data + _size);
	}
	reverse_iterator rbegin()
	{
		return reverse_iterator(this->end());
	}
	const_reverse_iterator rbegin() const
	{
		return reverse_iterator(this->end());
	}
	reverse_iterator rend()
	{
		return reverse_iterator(this->begin());
	}
	const_reverse_iterator rend() const
	{
		return reverse_iterator(this->begin());
	}

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
			for (size_type i = 0; i < _size; i++)
			{
				_alloc.construct(tmp + i, _data[i]);
			}
			for (size_type i = 0; i < _size; i++)
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
		for (size_type i = 0; i < _size; i++)
		{
			_alloc.destroy(_data + i);
		}
		_size = 0;
	}
	iterator insert(iterator position, const value_type& val)
	{
		return this->insert(position, 1, val);
	}
	iterator insert (iterator position, size_type count, const value_type& val)
	{
		size_type pos = position - begin();
		pointer tmp;
		size_type new_size = _size + count;
		size_type new_capacity = _capacity;
		if (count == 0)
			return (position);
		if (new_size > _capacity)
		{
			if (new_size < _capacity * 2)
				new_capacity *= 2;
			else
				new_capacity = new_size;
			tmp = _alloc.allocate(new_capacity);
			for (size_type i = 0; i < _size; i++)
			{
				if (i < pos)
					_alloc.construct(tmp + i, _data[i]);
				else
					_alloc.construct(tmp + i + count, _data[i]);
			}
			for (size_type i = pos; i < pos + count; i++)
				_alloc.construct(tmp + i, val);
			clear();
			_alloc.deallocate(_data, _capacity);
			_data = tmp;
			_size = new_size;
			_capacity = new_capacity;
		}
		else
		{
			for (size_type i = pos; i < _size; i++)
				_data[i + count] =  _data[i];
			for (size_type i = pos; i < _size; i++)
				_alloc.construct(_data + i, val);
			_size = new_size;
		}
		return (this->begin() + pos);
	}
	template <class InputIterator>
	iterator insert (iterator position, InputIterator first, InputIterator last)
	{
		size_type pos = position - this->begin();
		size_type	count = last - first;
		size_type new_size = _size + count;
		size_type new_capacity = _capacity;
		pointer tmp;
		if (first == last)
			return (position);
		if (new_size > _capacity)
		{
			if (new_size < _capacity * 2)
				new_capacity *= 2;
			else
				new_capacity = new_size;
			tmp = _alloc.allocate(new_capacity);
			for (size_type i = 0; i < _size; i++)
			{
				if (i < pos)
					_alloc.construct(tmp + i, _data[i]);
				else
					_alloc.construct(tmp + i + count, _data[i]);
			}
			for (size_type i = 0; i < count; i++)
				_alloc.construct(tmp + i + pos, first[i]);
			clear();
			_alloc.deallocate(_data, _capacity);
			_data = tmp;
			_size = new_size;
			_capacity = new_capacity;
		}
		else
		{
			for (size_type i = pos; i < _size; i++)
				_data[i + count] =  _data[i];
			for (size_type i = 0; i < count; i++)
				_alloc.construct(_data + i + pos, *(first + i));
			_size = new_size;
		}
		return (this->begin() + pos);
	}
	iterator erase( iterator position )
	{

		iterator it = this->begin();
		size_type index = position - this->begin();
		_alloc.destroy(_data + index);
		_size--;
		for (size_type i = index; i < _size; i++)
		{
			_data[i] = _data[i + 1];
		}
		return iterator(_data + index);
	}
	iterator erase( iterator first, iterator last )
	{
		size_type f_index = first - this->begin();
		size_type l_index = last - this->begin();
		size_type count = last - first;
		if (first == last)
			return (last);
		for (size_type i = f_index; i < l_index; i++)
			_alloc.destroy(_data + i);

		for (int i = f_index; i < _size; i++)
		{
			_data[i] = _data[i + count];
		}
		_size -= count;
		return iterator(_data + l_index);
	}
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
			if (count <= _size)
			{
				for (size_type i = count;  i < _size; i++)
					_alloc.destroy(_data + i);
			}
			else{
				for (size_type i = _size; i < count; i++)
				{
					_alloc.construct(_data + _size, value);
				}
			}
			_size = count;
		}
		else
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
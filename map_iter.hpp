#include <map.hpp>

template <class Iter>
class MapIterator
{
public:
	typedef Iter 							tree_type;
	typedef	typename Iter::pair_type 		pair_type;
	typedef typename Iter::Node 			node;
	typedef pair_type&						reference;
	typedef pair_type*						pointer;
	typedef std::ptrdiff_t 					difference_type;
	typedef typename tree_type::mapper_type	iterator_mapper;
	typedef typename tree_type::Node		node;
	

public:
	tree_type _tree;
	node* _root;
	
public:
	MapIterator(const node* n, const tree_type  tree):_tree(tree), _root(n)
	{
	}
	MapIterator(const MapIterator &other)
	:_tree(other._tree), _root(other._root)
	~MapIterator(){}
	MapIterator & operator = (const MapIterator &other)
	{
		this->_tree = other._tree;
		this->_root = other._root;
		return (*this);
	}
	bool operator==(const MapIterator & other)
	{
		return (this->_mapper == other._mapper);
	}
	bool operator!=(const MapIterator & other)
	{
		return (this->_mapper != other._mapper);
	}
	reference operator*(void)
	{
		return (*(*this->_mapper));
	}
	pointer operator->()
	{
		return (*(this->_mapper.base()));
	}
	
	MapIterator operator++ (int)
	{
		MapIterator<tree_type> tmp(*this);
		this->_mapper++;
		return (tmp);
	}
	MapIterator operator++ (void)
	{
		++this->_mapper;
		return (*this);
	}
	MapIterator operator-- (int)
	{
		MapIterator<tree_type> tmp(*this);
		this->_mapper--;
		return (tmp);
	}
	MapIterator operator-- (void)
	{
		--this->_mapper;
		return (*this);
	}
// {
	MapIterator operator+( int nbr )
	{
		MapIterator<tree_type> tmp(*this);
		tmp._mapper = this->_mapper + nbr;
		return tmp;
	}
}
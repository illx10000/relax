// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <unordered_map>
#include <list>
#include <iterator>

using std::list;
using std::unordered_map;

//每一次getintalue之后，都需要将get的value放入队列的首部
//setintalue的时候，如果cacheHolder满了之后，需要将cache尾端的数据淘汰
//因此实现的方法应该是 cacheHolder存储value在list的位置即可


class LRUCache
{
private:
	struct LRUCacheNode
	{
		int key;
		int value;
	};

public:
	LRUCache(int cap)
	{
		capacity = cap;
	}

	void put(const int& key, const int& v)
	{
		auto findIter = cacheHolder.find(key);
		if (cacheHolder.end() != findIter) //如果能找到key值，更新即可
		{
			keyElement.splice(keyElement.begin(), keyElement, findIter->second);
			findIter->second->value = v;
		}

		else
		{
			LRUCache::LRUCacheNode node;
			node.key = key;
			node.value = v;
			keyElement.push_front(node);

			cacheHolder[key] = keyElement.begin();

			if (cacheHolder.size() > capacity) //如果容量超限了，删除list的back
			{
				cacheHolder.erase(keyElement.back().key);
				keyElement.pop_back();
			}
		}
		
	}

	int get(const int& key)
	{
		auto findIter = cacheHolder.find(key);
		if (cacheHolder.end() != findIter)
		{
			int value = (findIter->second)->value;

			keyElement.splice(keyElement.begin(), keyElement, findIter->second); //[1,3,4,5](iterator==4) --> (4,1,3,5)
			return value;
		}

		return -1;
	}

private:
	list<LRUCache::LRUCacheNode>								keyElement;		//存储的key值
	unordered_map<int, list<LRUCache::LRUCacheNode>::iterator >	cacheHolder;	//实际上存储的数据
	int															capacity;		//cache的容量
};


int main()
{
	auto cache = new LRUCache(2 /* 缓存容量 */);
	int value;

	cache->put(1, 1);
	cache->put(2, 2);
	std::cout << std::endl << cache->get(1);       // 返回  1
	cache->put(3, 3);    // 该操作会使得密钥 2 作废
	std::cout << std::endl << cache->get(2);       // 返回 -1 (未找到)
	cache->put(4, 4);    // 该操作会使得密钥 1 作废
	std::cout << std::endl << cache->get(1);       // 返回 -1 (未找到)
	std::cout << std::endl << cache->get(3);       // 返回  2
	std::cout << std::endl << cache->get(4);       // 返回  4
}
/*
  ==============================================================================

    SharedPointerMap.h
    Created: 23 Oct 2019 12:14:07am
    Author:  gorangrubic

  ==============================================================================
*/







template<typename TKey, typename TObject>
class SharedPointerMap {
 
    public:
    
        std::map<TKey, std::shared_ptr<TObject>> Items;
    
		bool Contains(TKey key);

		void Add(TKey key, TObject * item);

		std::shared_ptr<TObject> Get(TKey key);
		TObject * GetPointer(TKey key);

    
};

template<typename TKey, typename TObject>
inline bool SharedPointerMap<TKey, TObject>::Contains(TKey key)
{
	
	if (Items.find(key) == Items.end()) {
		return false;
	}
	else {
		return true;
	}
}

template<typename TKey, typename TObject>
inline void SharedPointerMap<TKey, TObject>::Add(TKey key, TObject * item)
{
	if (Contains(key)) {
		Items.erase(key);
	}
	std::shared_ptr<TObject> p = std::shared_ptr<TObject>(item);
	Items.insert(std::make_pair(key, p));
}

template<typename TKey, typename TObject>
inline std::shared_ptr<TObject> SharedPointerMap<TKey, TObject>::Get(TKey key)
{
	if (!Contains(key)) return nullptr;
	return Items[key];
}

template<typename TKey, typename TObject>
inline TObject * SharedPointerMap<TKey, TObject>::GetPointer(TKey key)
{
	if (!Contains(key)) return nullptr;
	return Items[key].get();
}

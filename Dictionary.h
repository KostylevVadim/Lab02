template <class T, class R> class Dictionary {
private:
	int Hashfunction(T elem) {
		if (elem % 2==0)
			return 0;
		if (elem % 2 != 0)
			return 1;
		//return elem + 1;
	}
	int length;
public:
	vector<LinkedList<T>> keys;
	vector<LinkedList<R>> data;
	Dictionary() {}
	Dictionary(Pair<T,R>* a, int length) {
		for (int i = 0; i < length; i++) {
			//cout<<"Construct Append\n"<< a[i] << "\n";
			Append(a[i]);
		}
		
	}
	void Append(Pair<T,R> a) {
		int z = Hashfunction(a.value);
		if (z > data.size()) {
			//cout << 1 << "\n";
			//cout << a<<"\n";
			LinkedList<R> n(1);
			n.Set(0, a.value);
			LinkedList<T> n1(1);
			n1.Set(0, a.key);
			while (z > data.size()) {
				data.push_back(LinkedList<R>());
				keys.push_back(LinkedList<T>());
				//cout<<1<<" ";
			};
			data.push_back(n);
			keys.push_back(n1);
			//cout << 1 << "\n";
		}
		else
		if (z == data.size()) {
			//cout << 2 << "\n";
			///cout << a<<"\n";
			LinkedList<R> n(1);
			n.Set(0, a.value);
			LinkedList<T> n1(1);
			n1.Set(0, a.key);
			data.push_back(n);
			keys.push_back(n1);
			//cout << 2 << "\n";
		}
		else
		if (z < data.size()) {
			//cout << 3 << "\n";
			//cout << a<<"\n";
			data[z].Append(a.value);
			keys[z].Append(a.key);
			//cout << 3 << "\n";
		}
	}
	void Add(T key, R value) {
		Pair<T, R> a(key, value);
		Append(a);
	}
	size_t Count() {
		size_t x = 0;
		for (int i = 0; i < data.size(); i++) {
			if (data[i].GetLength() != 0) {
				
				x += data[i].GetLength();
			}
			
		}
		return x;
	}
	void remove(T key) {
		assert(ContainsKey(key) != 0);
		int y = 0;
		int t = 0;
		for (int i = 0; i < keys.size(); i++) {
			//cout << "List " << i << "\n";
			for (int j = 0; j < keys[i].GetLength(); j++) {
				//cout << keys[i].Get(j) << " "<<data[i].Get(j) << "\n";
				if (keys[i].Get(j) == key) {
					keys[i].DeleteKey(j);
					data[i].DeleteKey(j);
					return;
				}
				
					
			}
		}
	}
	bool ContainsKey(T key) {
		for (int i = 0; i < keys.size(); i++) {
			
			for (int j = 0; j < keys[i].GetLength(); j++) {
				
				if (keys[i].Get(j) == key) return 1;

			}
		}
		return 0;
	}
	R GetVal(T key) {
		assert(ContainsKey(key)!=0);
		for (int i = 0; i < keys.size(); i++) {
			
			for (int j = 0; j < keys[i].GetLength(); j++) {
				
				if (keys[i].Get(j) == key) return data[i].Get(j);

			}
		}
	}

};

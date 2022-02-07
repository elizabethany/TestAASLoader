#pragma once
#include <cstring>
#include <cassert>
#include <vector>
struct raw_loader_t {
	
	char* data;
	size_t position;
	raw_loader_t(char* d) : data(d) , position(0){}

	template<typename T>
	T rd() {
		
		T result = *reinterpret_cast<T*>(data + position);


		position += sizeof(T);


        if constexpr(sizeof(T) == 2) {
            return _byteswap_ushort(result);
        }
        else if constexpr(sizeof(T) == 4) {
            unsigned x = _byteswap_ulong(*reinterpret_cast<unsigned*>(&result));
            return *reinterpret_cast<T*>(&x);
        }
        else if constexpr(sizeof(T) == 8) {
            unsigned long long x = _byteswap_uint64(*reinterpret_cast<unsigned long long*>(&result));
            return *reinterpret_cast<T*>(&x);
        }
		return result;
	}

	template<typename T, typename TPtr>
	void read_n_into(TPtr* out, unsigned n) {
		
		for(unsigned i = 0; i < n; ++i) {
			reinterpret_cast<T*>(out)[i] = rd<T>();
		}

	}
	template<typename lengthtype, size_t n>
	void read_string(idArray<char, n>& into) {
		lengthtype l = rd<lengthtype>();
		read_n_into<char>(&into.ptr, l);
	}

	template<typename T,typename size_type = unsigned>
	void read_vector(std::vector<T>& vec) {
		size_type sz = rd<size_type>();
		vec.resize(sz);

		memcpy(vec.data(), data+position, sz*sizeof(T));
		position+=sizeof(T)*sz;
	}

	~raw_loader_t() {
		free(data);
	}
};
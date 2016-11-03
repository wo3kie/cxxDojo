#include <atomic>

int main(int rand, char * argv[]){
	std::atomic<int> atomic;

	atomic.store(rand);

	atomic.fetch_add(24);

	int i = 1 + 24;
	atomic.compare_exchange_strong(i, 0);

	return atomic.load();
}


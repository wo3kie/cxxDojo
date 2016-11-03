//

int function(
	int i1,
	int i2,
	int i3,
	int i4,
	int i5,
	int i6,
	int i7
){
	int local = 0;

	local += i1;

	local -= i2;

	local *= i3;

	local /= i4;

	local <<= i5;

	local >>= i6;

	return local;
}

int main(){
	function(1, 2, 3, 4, 5, 6, 7);
}


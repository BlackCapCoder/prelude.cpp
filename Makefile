test:
	cat examples/*.cpp | cpp -P | awk '/./'

run: test

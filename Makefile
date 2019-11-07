test:
	cat examples/*.cpp | cpp -P -trigraphs | awk '/./'

run: test

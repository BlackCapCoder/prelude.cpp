test:
	cpp -P examples/*.cpp | awk '/./'

run: test

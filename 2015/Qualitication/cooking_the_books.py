from operator import ge, le

def get_digit(ar, tried, op):
	possibilities = [i for i in ar if i not in tried]
	if possibilities:
		return op(possibilities)	
	else:
		return False

def get_index(ar, digit, ind):
	return max(i for i, j in enumerate(ar) if j == digit and i >= ind)

def get_position(ar, init, pos, op):
	while init < pos and op(ar[init], ar[pos]):
		init += 1
	return init

def find_number(n, max_min, le_ge):
	number = list(n)	
	tried = []
	ind = 0
	
	while number == n and ind < len(n)-1:
		digit = get_digit(number, tried, max_min)
		if not digit:
			break
		pos = get_index(number, digit, 0)
		ind = get_position(number, ind, pos, le_ge)
		
		if digit != '0' or ind != 0:
			number[pos], number[ind] = number[ind], number[pos]
		
		tried.append(digit)
	
	return number
	
case = 1
for _ in range(int(input())):
	n = list(input())
	print("Case #{}: {} {}".format(case, ''.join(find_number(n, min, le)), ''.join(find_number(n, max, ge))))
	case += 1

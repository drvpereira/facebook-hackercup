from itertools import chain, combinations

def food_combinations(foods):
  return list(chain.from_iterable( combinations(foods, n) for n in range(1, len(foods) + 1) ))

case = 1
for _ in range(int(input())):
	gp, gc, gf = map(int, input().split())
	foods = []
	
	for _ in range(int(input())):
		foods.append(list(map(int, input().split())))
	
	found_combination = False
	for comb in food_combinations(foods):
		p = c = f = 0
		
		for food in comb:
			p += food[0]
			c += food[1]
			f += food[2]
			
		if p == gp and c == gc and f == gf:
			found_combination = True
			break
	
	print('Case #{}: {}'.format(case, 'yes' if found_combination else 'no'))
	case += 1

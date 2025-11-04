import sys
def run_knapsacks(items, capacity):
    print("\n1. Packing Optimization")
    n = len(items)
    
    dp = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]
    for i in range(1, n + 1):
        item = items[i - 1]
        for w in range(1, capacity + 1):
            if item['weight'] <= w:
                dp[i][w] = max(item['value'] + dp[i - 1][w - item['weight']], dp[i - 1][w])
            else:
                dp[i][w] = dp[i - 1][w]

    packed_opt, w = [], capacity
    for i in range(n, 0, -1):
        if dp[i][w] != dp[i-1][w]:
            packed_opt.append(items[i-1]['name'])
            w -= items[i-1]['weight']
    
    print(f"[Knapsack]")
    print(f"  > Value: {dp[n][capacity]}, Items: {', '.join(reversed(packed_opt))}")

    ratio_items = sorted(items, key=lambda x: x['value'] / x['weight'] if x['weight'] > 0 else float('inf'), reverse=True)
    packed_greedy, val_greedy, w_greedy = [], 0, 0
    for item in ratio_items:
        if w_greedy + item['weight'] <= capacity:
            packed_greedy.append(item['name'])
            w_greedy += item['weight']
            val_greedy += item['value']

    print(f"\n[Greedy (by ratio)]")
    print(f"  > Value: {val_greedy}, Items: {', '.join(packed_greedy)}")

def run_kadanes(daily_data):
    print("\n\n### 2. Best Travel Days (Kadane's) ###")
    print(f"Ratings: {daily_data}")
    
    
    max_so_far, current_max = -sys.maxsize, 0
    start, end, temp_start = 0, 0, 0

    for i, val in enumerate(daily_data):
        current_max += val
        if current_max > max_so_far:
            max_so_far, start, end = current_max, temp_start, i
        if current_max < 0:
            current_max, temp_start = 0, i + 1
    
    if all(x < 0 for x in daily_data): max_so_far = max(daily_data) # Handle all-negatives
         
    print(f"[Result] Max Score: {max_so_far} (from Day {start + 1} to Day {end + 1})")

def run_lcs(list1, list2):
    print("\n\n3. Packing List Comparison (LCS)")
    print(f"List 1: {list1}\nList 2: {list2}")
    m, n = len(list1), len(list2)
    
    dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if list1[i - 1] == list2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    common = []
    i, j = m, n
    while i > 0 and j > 0:
        if list1[i - 1] == list2[j - 1]:
            common.append(list1[i - 1])
            i, j = i - 1, j - 1
        elif dp[i - 1][j] > dp[i][j - 1]: i -= 1
        else: j -= 1
    
    print(f"[Result] Found {dp[m][n]} common items: {', '.join(reversed(common))}")

def main():
    print("Travel Optimizer (Short Version)")
    all_items = []
    try:
     
        capacity = int(input("Max luggage weight (kg): "))
        while True:
            name = input("Item name ('done' to stop): ")
            if name.lower() == 'done': break
            weight = int(input(f"  {name} weight: "))
            value = int(input(f"  {name} value: "))
            all_items.append({'name': name, 'weight': weight, 'value': value})
        
        if all_items: run_knapsacks(all_items, capacity)

        line = input("\nDaily ratings (e.g., 5 -2 8): ")
        ratings = [int(r) for r in line.split()]
        if ratings: run_kadanes(ratings)

        if all_items:
            print("\nMaster Item List:")
            for i, item in enumerate(all_items): print(f"  {i + 1}: {item['name']}")
            
            line1 = input("Trip 1 item numbers (e.g., 1 3 4): ")
            list1 = [all_items[int(i)-1]['name'] for i in line1.split()]
            
            line2 = input("Trip 2 item numbers (e.g., 1 2 5): ")
            list2 = [all_items[int(i)-1]['name'] for i in line2.split()]
            
            if list1 and list2: run_lcs(list1, list2)
            
    except (ValueError, IndexError):
        print("\nError: Invalid input. (Bad number or item index).")
    finally:
        print("\nDone")

if __name__ == "__main__":
    main()
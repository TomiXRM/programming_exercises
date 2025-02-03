def is_geometric_sequence(arr):
  n = len(arr)

  if n == 0:
    return "No"

  if arr[0] == 0:
      return "No"

  if 0 in arr[1:]:
      if all(x == 0 for x in arr[1:]):
          return "Yes"
      else:
          return "No"

  if 0 in arr[1:]:
    return "No"

  if n == 2:
    return "Yes"

  if arr[1] % arr[0] != 0:
    return "No"

  ratio = arr[1] // arr[0]

  for i in range(2, n):
    if arr[i] % arr[i - 1] != 0 or arr[i] // arr[i - 1] != ratio:
      return "No"

  return "Yes"

n = int(input())
arr = list(map(int, input().split()))

print(is_geometric_sequence(arr))
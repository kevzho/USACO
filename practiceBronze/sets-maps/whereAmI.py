with open("whereami.in", "r") as f:
    lines = f.readlines()

n = int(lines[0])
mailboxes = lines[1]

mini = n

def find_mini(n, s):
    for k in range(1, n + 1):
        seen = set()
        for i in range(n - k + 1):
            substring = mailboxes[i: i+ k]
            if substring in seen:
                break 

            seen.add(substring)

            if i == (n - k):
                return k
            
with open("whereami.out", "w") as f:
    f.write(str(find_mini(n, mailboxes))) 

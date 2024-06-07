def main():
    height = get_input("Height: ")

    for i in range(height):
        for j in range(height-1, -1, -1):
            if (j <= i):
                print("#", end="")
            else:
                print(" ", end="")
        print()


def get_input(prompt):
    while True:
        try:
            print(prompt, end="")
            n = int(input())
            if 0 < n < 9:
                return n
        except ValueError:
            pass


main()

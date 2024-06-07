def main():
    dollar = get_input("Change: ")
    cents = dollar * 100

    # Calculate the number of quarters to give the customer
    quarters = (cents - (cents % 25)) / 25
    cents = cents - (quarters * 25)

    # Calculate the number of dimes to give the customer
    dimes = (cents - (cents % 10)) / 10
    cents = cents - (dimes * 10)

    # Calculate the number of nickels to give the customer
    nickels = (cents - (cents % 5)) / 5
    cents = cents - (nickels * 5)

    # Calculate the number of pennies to give the customer
    pennies = cents

    # Sum coins
    coins = quarters + dimes + nickels + pennies

    print(int(coins))


def get_input(prompt):
    while True:
        try:
            print(prompt, end="")
            n = float(input())
            if n > 0:
                return n
        except ValueError:
            pass


main()

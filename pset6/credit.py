from cs50 import get_string

cardNum = get_string("What is your card number: ")
count = len(cardNum)

if cardNum[0]=='4':
    startNum = int(cardNum[0])
else:
    startNum = int(cardNum[0] + cardNum[1])

sum1 = 0
sum2 = 0
for i in range(count-2, -1, -2):
    pdtBy2 = int(cardNum[i])*2
    if pdtBy2 > 9:
        sum1 = sum1 + (pdtBy2%10)
        pdtBy2 = int(pdtBy2/10)
        sum1 = sum1 + (pdtBy2%10)
    else:
        sum1 = sum1 + pdtBy2

if count%2 == 0:
    rem_startIndex = 1
else:
    rem_startIndex = 0
for i in range(rem_startIndex, count, 2):
    sum2 = sum2 + int(cardNum[i])

finalSum = sum1 + sum2
if count==15 and (startNum==34 or startNum==37) and finalSum%10==0:
    print("AMEX\n");

elif count==16 and (startNum==51 or startNum==52 or startNum==53 or startNum==54 or startNum==55) and finalSum%10==0:
    print("MASTERCARD\n");

elif (count==13 or count==16) and startNum==4 and finalSum%10==0:
    print("VISA\n");

else:
    print("INVALID\n");
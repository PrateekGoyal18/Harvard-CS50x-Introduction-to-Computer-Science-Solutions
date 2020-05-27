text = input("Enter the text: ")
length = len(text)

count_l=0
count_w=0
count_s=0
for i in range(length):
    if text[i] in ['.', '!', '?']:
        count_s+=1
    elif text[i] == ' ':
        count_w+=1
    elif text[i].isalpha()==True:
        count_l+=1
count_w+=1

# average number of letters per 100 words in the text
avg_lw = (count_l*100)/count_w

# average number of sentences per 100 words in the text
avg_sw = (count_s*100)/count_w

# Formula for Coleman-Liau index
index = round(0.0588*avg_lw - 0.296*avg_sw - 15.8)

# US grade level needed to understand the text
if index<1:
    print("Before Grade 1")
elif index>16:
    print("Grade 16+")
else:
    print(f"Grade {index}")
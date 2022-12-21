. assert.sh

assert "./megaphone \"shhhhh... I think the students are asleep...\"" "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..."
assert "./megaphone Damnit \" ! \" \"Sorry students, I thought this thing was off.\"" "DAMNIT ! SORRY STUDENTS, I THOUGHT THIS THING WAS OFF."
assert "./megaphone" "* LOUD AND UNBEARABLE FEEDBACK NOISE *"
assert_end examples

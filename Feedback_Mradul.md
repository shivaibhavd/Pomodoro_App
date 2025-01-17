Feedback:
1. main.cpp remains in src/ (minor)
2. where is the cmake file to build ? (major)
3. See everything marked as // feedback_15Jan in the codebase for more feedback
4. there is virtually no error handling implemented (major)
5. there are virtually no comments in the codebase (minor)
6. TODO: Can I run multiple instances of your app parallaly ? (Try and check)
7. Dependency inversion principle is broken in case of Notifier

Overall Feedback;
1. Very readable code
2. Good implementation of the design at lower level
3. Need to improve the behaviour of the APP by thinking of user experience/behaviour
4. Needs better Error Handling 
    4.1. think at APP level not at function level for improving in this 
    4.2. think of what needs to be 
5. 


Think but do not implement:
1. What changed would you need to make to get the app to spawn more instances of the app ?

# feedback 2: Mradul on 17 Jan
1. If you have added include directory in CMakelist, you do not need to give path to the header file
2. All user notifications should make use of notifier and not rely on cout
3. On run failure of the app, consider implementing a recovery strategy
4. Feedback_17Jan
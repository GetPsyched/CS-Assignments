# CSPE35 - Lab Manual

## Lab 1 - Basic Introduction & Installation

1. Reading about Android
    - What is Android and its history?
    - What are the versions of Android?
    - What is the architecture of Android?
    - What are API levels?
    - What are the activities in Android?
    - What is the life cycle of an activity?

2. Installation of Android Studio.

3. Create a new project and build a simple empty activity application.

4. Learn how to build your application by building an APK and test it via:
    - USB debugging on any physical Android device.
    - Virtual device inside of Android Studio

## Lab 2 - Hello, World!

1. Build your first "Hello, World!" application.
2. Build a "Hello, World!" application using Toast.
3. Build an application containing "Hello, World!" as a value in a `TextView`.
4. Create your own values in `string.xml`.
5. Add background to the `TextView` in question 3 using:
    - Hexadecimal value in `XML` layout.
    - `dimens.xml` values.
6. Add margins to the `TextView` in question 3 using:
    - Hexadecimal value in `XML` layout.
    - `dimens.xml` values.

## Lab 3 - Layouts & UI Control Components

1. Use a Linear Layout that contains 4 buttons as UI components with the following attribute property set:
    - **Layout:** `android: divider`, `android: orientation`, `android: layout_width`, `android: layout_height`, etc.
    - **Button:** `android: layout_width`, `android: layout_height`, `android: inputType`, `android: marginTop`, `android: text`, etc.

2. Using a Relative Layout, design a form that inputs the following:
    - First & last names
    - Gender (using radio buttons)
    - DoB (using date picker)

    For this, use the following attribute property set:
    - **Layout:** `android: layout_alignParentRight`, `android: layout_alignParentLeft`, `android: layout_alignParentBottom`, `android: layout_alignParentTop`, etc.
    - **RadioButton:** `android: layout_width`, `android: layout_height`, `android: text`, `android: checked`, `android: textSize`, `android: textColor`, etc.
    - **EditText:** `android: layout_width`, `android: layout_height`, `android: editable`, `android: text`, `android: background`, etc.

3. Using a Table Layout and `EditText`, design the following:
    <table>
        <tr>
            <th colspan="3">This is row 1</th>
        </tr>
        <tr>
            <td>R2C1</td>
            <td>R2C2</td>
            <td>R2C3</td>
        </tr>
        <tr>
            <td>R3C1</td>
            <td>R3C2</td>
            <td>R3C3</td>
        </tr>
        <tr>
            <td colspan="2">R4C1</td>
            <td>R4C2</td>
        </tr>
    </table>

4. Using a Grid Layout, `ImageView` and `TextView` UI controls, design the following:
    <image src=""></image>

5. Create a login page for an online shopping platform using Learned Layouts.
    - Create a `TextView` for the title.
    - Add 2 `EditText`s for the username and password.
    - Add the login button.
    - Create a checkbox and a radio button.

## Lab 4 - Activity Lifecycle

Create an application to show the lifecycle of an activity. Include the following functions:
    - `onCreate`
    - `onStart`
    - `onResume`
    - `onPause`
    - `onStop`
    - `onRestart`
    - `onDestroy`
Use Toast and logcat to display when each function gets called.

## Lab 5 - Event Creation
For all the following apps, you must use the following:
- `onClick` method
- Delegation Event Model (Android Event Handlers)

Apps:
1. Create a calculator app using buttons for every operation.
2. Create a tailor app which takes various parameters such as:
    - Name
    - Phone number
    - Address
    - Height (using `EditText`)
    - Gender (using `RadioButton`)
    - Size (using `Spinner`)

    Calculate the price on press of the submit button using the following table:

    | Size          | Gender        | Price (per meter)  |
    | ------------- |:-------------:| ------------------:|
    | L             | Male          | ₹300               |
    |               | Female        | ₹500               |
    | XL            | Male          | ₹400               |
    |               | Female        | ₹700               |
    | XXL           | Male          | ₹500               |
    |               | Female        | ₹900               |

3. Create a dice roller app which displays any random number between 1 and 6 on button click.

## Lab 6 - `ListView`

1. Create an application that lists the states of India using ListView

2. Create an application that lists the various android Versions till date .

3. Design a Custom ListView as follows:
    <image src=""></image>

4. Design a `ListView` that will display each country's name along with its currency and flags as shown in figure below:
    <image src=""></image>

    Add entries in the `ListView` using:
    - String-array in `strings.xml`
    - `ArrayAdapter` Class in java

## Lab 7 - Fragments

1. Create an application that uses fragments inside an activity.
2. Create a tabbed activity and create 4 sliding tabs using:
    - `ViewPager` widget
    - `SectionsPagerAdapter`

## Lab 8 - Activities and Intents

1. Create an application with 2 activities and study about `<intent-filter>` in Manifest Files and alternatively make each activity main and launcher one at a time.
2. Use a button to make intent and move between various activities.
3. Design a login page that forwards user to new activity using intent on successful login.
4. Design a 2 activity long registration form such that on `nextPageButton`, activity 1 proceeds to the next page of the form only if all the fields in current form are filled.
5. Design an app named `Loopy` that has 4 activities in a way that the intents form a loop as shown in figure:

                                           Intent                       Intent                 Intent

Activity 1                        Activity 2            Activity 3             Activity 4

6. Pass Key Values in Intent in above question and retrieve it in second activity (Forward Parsing)
7. Perform Backward Parsing in above question
8. Make a form in one activity and pass the values in next activity and display all filled details in the form or design a login page.
9. Try both implicit and explicit intent for the above parts.

## Lab 9 - Data Storage

1. Use shared Preferences to store and retrieve key value pairs stored in Shared Preferences
2. Use Content Provider and store data in SQLite.

## Lab 10 - Project

Design any application using all above learned techniques to solve a real life problem or for use in daily life.

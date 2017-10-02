	Peter Tran Huynh
	CSCI 4239 (Advance Graphics)
	Spring 2017
	University of Colorado Boulder
	Homework 6 - OpenGL ES on iOS and Android

	---ESTIMATED-TIME-SPENT--- 
	10 hours and 30 minutes (I hate App IDE setup...)

	---Description---
	Create a program that allows a scene to be viewed in 3D from any direction
	under user control that can be run on the iPhone/iPod/iPad or Android.

	You must build some solid 3D objects yourself using OpenGL ES.  In particular,
	there are a number of frameworks such as GLKit on the iPhone that permits you
	to write applications without using OpenGL ES.  In this assignment I would like
	you to get some exposure to the nuts and bolts of OpenGL ES, so using such
	frameworks is prohibited.

	You have many choices as to accomplish this depending on your interest.

	If you care about portability, you could start with my simple application and explore 
	features such as lighting and textures, gestures, and so on.  My example borrowed 
	heavily from Rideout's iPhone 3D programming and develop the core code in C++ and
	only provide a native wrapper.

	Alternatively you may start with one of the Qt examples provided with Qt Creator that uses
	OpenGL ES and improve on it.  Qt provides examples for both iOS and Android.

	Or you may use one of the Objective C examples for iOS that uses OpenGL (but not GLkit) 
	provided by Apple.

	Or if you like Java you can add to an OpenGL ES example code written entirely in Java and
	provided as part of the Android SDK.

	This is potentially a difficult assignment since you need to install the Xcode
	environment for the iPhone or the Android SDK/NDK/IDE.  Therefore you may work in
	pairs for this assignment with somebody a bit further along on the curve.  Your
	README should clearly tell me what the contribution of each team member was.

	When you submit the assignment, the person whose environment you used should
	upload the project.  Look at my examples on how to clean out stuff I don't
	need, and upload only that.

	For the presentations, the presentation would be by one individual.

	If the iPhone/Android is your thing, please volunteer.  However, please bear in
	mind that many people in class are just starting, so be careful not to talk over
	people's heads.

	---Results---
	Using example 9 as the initial template, and HW 5 FRAG and VERT shaders, I implemented static shader via rng
	x and y position added to the Red color value, along with standard color gradience based on rotational position.
	I also added to the object shape, creating a crystal-like object.

	---Folders---
	Peter-Huynh_HW6_iOS         - Assignment description and documentation ZIPPED

	---Files---
	~.h / ~.cpp                 - C++ Files
	~.xcodeproj                 - Xcode Project
	EVERYTHING ELSE             - Assets, configuration and build settings for Xcode project
	README                      - This file

	---Executable-Commands---
	Open .xcodeproj in xcode on a Mac nad Press run
		- Works best on newer devices, such as iPhone SE or 7

	---GUI---
	 App auto rotates
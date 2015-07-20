# GitHub Workflow - Work as a Team

I know this is a little project, but I want to do it properly, and show to you
how we should work as a group/team. I may be too much. BUT I STILL THINK, that
we must start to work like this, or we will fall back on our bad style of
teamworking. SO PLEASE, PROVE IT TO ME THAT WE CAN MAKE IT.
I think everyone on us, can be really fluent with git. At the start you may
think that it's may not be really usefull, but more you masteries it, more you
will want to use it. It's really way more usefull that ANYTHING else, to manage 
a code repository.

GitHub Flow is a lightweight, branch-based workflow that supports teams and
projects where deployments are made regularly. This guide explains how and why
GitHub Flow works.

You can also look a this [site](http://pcottle.github.io/learnGitBranching/).
It explain very well how git work, and also provide nice git graph/tree.

## Doing Your Work

### Create a Branch

When you're working on a project, you're going to have a bunch of different
features or ideas in progress at any given time – some of which are ready to go,
 and others which are not. Branching exists to help you manage this workflow.

When you create a branch in your project, you're creating an environment where
you can try out new ideas. Changes you make on a branch don't affect the
`master` branch, so you're free to experiment and commit changes, safe in the
knowledge that your branch won't be merged until it's ready to be reviewed by
someone you're collaborating with.

### ProTip
Branching is a core concept in Git, and the entire GitHub Flow is based upon it.
There's only one rule: anything in the `master` branch is always fonctionnal.

To create a new branch and start working on it:

```shell
# Checkout the master branch - you want your new branch to come from master
git checkout master

# Create a new branch named newfeature (give branch a simple informative name)
git branch newfeature

# Switch to your new branch
git checkout newfeature
```

### Add commits

Once your branch has been created, it's time to start making changes. Whenever
you add, edit, or delete a file, you're making a commit, and adding them to your
branch. This process of adding commits keeps track of your progress as you work
on a feature branch.

Commits also create a transparent history of your work that others can follow to
understand what you've done and why. Each commit has an associated commit
message, which is a description explaining why a particular change was made.
Furthermore, each commit is considered a separate unit of change.
This lets you roll back changes if a bug is found, or if you decide to head in
a different direction.

### ProTip

Commit messages are important, especially since Git tracks your changes and
then displays them as commits once they're pushed to the server.
By writing clear commit messages, you can make it easier for other people to
follow along and provide feedback.

## Open a Pull Request

### Cleaning Up Your Work

Prior to submitting your pull request, you might want to do a few things to
clean up your branch and make it as simple as possible for the original repo's
maintainer to test, accept, and merge your work.

You can open a Pull Request at any point during the development process: when you have little or no code but want to share some screenshots or general ideas, when you're stuck and need help or advice, or when you're ready for someone to review your work. By using GitHub's @mention system in your Pull Request message, you can ask for feedback from specific people or teams, whether they're down the hall or ten time zones away.

If any commits have been made to the upstream master branch, you should rebase
your development branch so that merging it will be a simple fast-forward that
won't require any conflict resolution work.

```shell
# Update master with your repo's master branch
git checkout master
git pull origin master

# If there were any new commits, rebase your development branch
git checkout newfeature
git rebase master
```

Now, it may be desirable to squash some of your smaller commits down into a
small number of larger more cohesive commits. You can do this with an
interactive rebase :

```shell
# Rebase all commits on your development branch
git checkout 
git rebase -i master
```

This will open up a text editor where you can specify which commits to squash.
USE VIM ! PLEASE. It's way more simple and looks more BADASS.
The git rebase is an awesome and very usefull feature you should use it.

### Submitting - Discuss and review your code

EVERYTHING MUST BE WRITE IN ENGLISH ! PLEASE.

Once a Pull Request has been opened, the person or team reviewing your changes may have questions or comments. Perhaps the coding style doesn't match project guidelines, the change is missing unit tests, or maybe everything looks great and props are in order. Pull Requests are designed to encourage and capture this type of conversation.

You can also continue to push to your branch in light of discussion and feedback about your commits. If someone comments that you forgot to do something or if there is a bug in the code, you can fix it in your branch and push up the change. GitHub will show your new commits and any additional feedback you may receive in the unified Pull Request view.

### ProTip

Pull Request comments are written in Markdown, so you can embed images and emoji, use pre-formatted text blocks, and other lightweight formatting.

## Accepting and Merging a Pull Request

The creator of a pull request should NEVER merge it himself. Why ?
Because the code that he want to push MUST be check by someone else. If this is 
okay for him, he should leave a comment like "ok for me, merging", or whatever...
If anything is wrong, he must comment the pull request for the AUTHOR to correct
it. Then we can improve our self, and also check and know what everyone is doing.

In cases where the merge would be a simple fast-forward, you can automatically do the merge by just clicking the button on the pull request page on GitHub.
Do not forget to delete the branch after the merge !
GitHub will ask it to you after it, but if you want to do it manually:

```shell
git branch -d newfeature
```

### Manually Merging a Pull Request

DO NOT DO THAT. Exept you know exactly what you're doing. Then, you should know 
the command to type :D.

## /!\ Important note

Nothing have to be directly push on `master`. It's striclty forbidden !
Execpt there is a good reason AND everyone agree.

Do not forget that you have to write in english. Comment your pull request,
squash your commit, pull and commit often on your branch.

You should really read this, I hope you will.
Because there is many things that missing and maybe mistake that I made, then
you should offer a correction or improve this.

If you have any problem with the use of git, come ask me. I will show you how 
to do it, and also explain it to you. It's a good way to learn git, and you 
will see, it's a really powerfull tool.

```
     ____________________________________________________
    |.==================================================,|
    ||  I WILL MERGE AND REVIEW PULL REQUESTS QUICKLY   ||
    ||  I WILL MERGE AND REVIEW PULL REQUESTS QUICKLY   ||
    ||  I WILL MERGE AND REVIEW PULL REQUESTS QUICKLY   ||
    ||  I .----.ERG,                                    ||
    ||   / ><   \  /                                    ||
    ||  |        |/\                                    ||
    ||   \______//\/                                    ||
    ||   _(____)/ /                                     ||
    ||__/ ,_ _  _/______________________________________||
    '===\___\_) |========================================'
         |______|
         |  ||  |
         |__||__|
         (__)(__)
```

# C++ Coding Standards

This document attempts to describe a few C++ coding standards that are being used.

Our goal is to write **uniform** (consistent, patterned), **simple**, **readable**, **manageable** (modular) and **effective** (for compiling and running) code!

The ultimate goal of these guidelines is the increase readability and maintainability of our common source base.

# C++ Source Code - General

Comments are one critical part of readability and maintainability. Everyone knows they should comment their code, and so should you. When writing comments, write them as English prose, which means they should use proper capitalization, punctuation, etc. Aim to describe what the code is trying to do and why, not how it does it at a micro level.

## Style

### Indentation and spacing
In all cases, indent C++ code by four SPACES... or tabs, but spaces is prefer.

### Comment Formatting
In general, prefer C++ style (//) comments. These nest properly and are better behaved in general than C style comments.

### Parameter ordering

First input, then output. You can wrap your parameters in the style like this:

    int calc_x(int x, float z,
                const my_namespace::MyClass::ConstPtr ptr_y
                float* w) {
      // Code goes here ...
    }

## C++ functionaities

### Define variables length

It's fine to use `int`, `float`, `double`, etc. if you just want to use some variables locally. Otherwise, when necessary, think about using `uint8_t`, `int16_t`, `float32_t`, etc. 

### Const

It protects data from being illegally modified by throwing an error to you. Using `const` where possible is strongly recommended. You may have bigger chance of getting compiler error, but you will have less time spent on debugging because the `const`, throwing the error, tells you exactly where the problem is.

**Const Correctness**: always do `const` the "right" way:

    int const x;

instead of

    const int x;

It makes more sense if you have something like

    int const * p;

which means the object the pointer points to is a `const`, while

    int * const p;

means the pointer itself is a `const`, while

    int const * const p;

means both. So you get the idea: `const` describes the things on its left; therefore, make it always `right`. For more information, please checkout http://www.parashift.com/c++-faq-lite/const-correctness.html.

### Explicit constructor

Use it when you feel necessary, especially for the case that the constructor has one or more class type varialbes as parameters.

### Static type

Do not declare dynamic type (vector, class, etc.) as static.

### Type casting

Use static_cast<TYPE> for simple type conversions, dynamic_cast<TYPE> for complex type conversions and interpret_cast<TYPE> for pointers and direct memory block reinterpretation (for example, get a float form char[4]). In other words,

    float f = 3.1415926;
    int i = static_cast<int>(f); // Good.
    A a; B b = dynamic_cast<A>(a); // Usually good.
           b = (A) a; // Bad.
    char[4] float_bytes = {...};
    f = *(interpret_cast<float*>(float_bytes)); // Good.
    f = *((float*) float_bytes); // Bad.

This will become clear when you start to work with more complex data types.

### Self-increment

Though `++i` is faster than `i++`, you can actually use either of them for primitive types (int, float, etc.) as you like; but for more complex tyes like iterators, preincrement is always favored.

    `++i`; // Good.
    `i++`; // Bad.

## File Headers

Ok, finally, I think that we should not put the EPITECH header in our souces files.
Why ? Because it's really weird, and more important it create so __fucking__ many merging conflicts.
I hate that. You should too. So no header please :).

## \#include ordering

Immediately after the header file comment (and include guards if working on a header file), the minimal list of #includes required by the file should be listed. We prefer these \#includes to be listed in this order:

    1. Local/Private Headers
    2. System/Global #includes

## Header files

### Use “`.hpp`” please, otherwise emacs is doing shit with the syntax color and indentation

Style 1: `.hpp` for definition; `.cpp` for implementation. (e.g. `my_class.hpp`)

### The #define Guard

    #ifndef _[FILE]_HPP_
    #define _[FILE]_HPP_

    // Your code goes here …
    
    #endif

Example: for file `bar.hpp`, the `#define` guard is: `_BAR_HPP_`.

## Naming

### In code

`ExampleName`: for class/struct/union names (not variables or class instances names), type names;

`exampleName`: for instances, variables names and functions (class methods) only, and, although allowed, is not recommended;

`isConditionSatisfied`: boolean variables;

`_example_name`: for function parameters (`int func(int _x, float _param)`);

`EXAMPLE_NAME`: for macros, enums and defines.

# Compiler Issues

## Treat Compiler Warning as Errors!
If your code has compiler warnings in it, something is wrong — you aren’t casting values correctly, you have “questionable” constructs in your code, or you are doing something legitimately wrong. Compiler warnings can cover up legitimate errors in output and make dealing with a translation unit difficult.

## Write Portable Code 
In almost all cases, it is possible and within reason to write completely portable code. If there are cases where it isn’t possible to write portable code, isolate it behind a well defined (and well documented) interface.

In practice, this means that you shouldn’t assume much about the host compiler.

***
Note: This is partially copied from the different coding standards that looks
good, feel free to improve it.

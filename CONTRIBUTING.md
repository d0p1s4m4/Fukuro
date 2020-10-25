# Contributing to Fukurō

First, thanks for taking the time to contribute! :heart_eyes_cat::+1:

#### Table Of Contents

- [Code of Conduct](#code-of-conduct)
- [How Can I Contribute?](#how-can-i-contribute-)
  * [Reporting Bugs](#reporting-bugs)
      - [Before Submitting A But Report](#before-submitting-a-but-report)
      - [How Do I Submit A (GOOD) Bug Report](#how-do-i-submit-a--good--bug-report-)
  * [Your First Code Contribution](#your-first-code-contribution)
- [Styleguides](#styleguides)
  * [Git Commit Message](#git-commit-message)
  * [C Coding Style](#c-coding-style)

## Code of Conduct

This project and everyone participating in it is governed by the [Fukurō Code of Conduct](CODE_OF_CONDUCT.md). By participating, you are expected to uphold this code.
Please report unacceptable behavior to [conduct@fukuro.dev](mailto:conduct@fukuro.dev).

## How Can I Contribute?

### Reporting Bugs

This section guide you through submitting a bug report for Fukurō. Following these guidelines helps maintainers and the community understand your report, reproduce the behavior, and find related reports.

Before creating bug reports, please check [this list](#before-submitting-a-bug-report) as you might find out that you don't need to create one. When you are creating a bug report, please [include as many details as possible](#how-do-i-submit-a-good-bug-report).

> **Note:** If you find a **Closed** issue that seems like it is the same thing that you're experiencing, open a new issue and include a link to the original issue in the body of your new one.

#### Before Submitting A Bug Report

* **Perform a [cursory search](https://github.com/search?q=+is%3Aissue+user%3Fukuro)** to see if the problem has already been reported. If it has **and the issue is still open**, add a comment to the existing issue instead of opening a new one.

#### How Do I Submit A (GOOD) Bug Report?

Bugs are tracked as [GitHub issues](https://guides.github.com/features/issues/).

Explain the problem and include additional details to help maintainers reproduce the problem:

* **Use a clear and descriptive title** for the issue to identify the problem.
* **Describe the exact steps which reproduce the problem** in as many details as possible.
* **Describe the behavior you observed after following the steps** and point out what exactly is the problem with that behavior.
* **Explain which behavior you expected to see instead and why.**
* **Include screenshots** which clearly demonstrate the problem if needed. 
* **include a stack trace**
* **If the problem wasn't triggered by a specific action**, describe what you were doing before the problem happened and share more information using the guidelines below.

Provide more context by answering these questions:

* **Can you reliably reproduce the issue?** If not, provide details about how often the problem happens and under which conditions it normally happens.

Include details about your configuration and environment:

* **Which version of Fukurō are you using?**
* **Are you running Fukurō in a virtual machine?** If so, which VM software are you using ?
* **Are you running Fukurō on real hardware?** If so, provide information about it.

### Your First Code Contribution

Unsure where to begin contributing to Fukurō? You can start by looking through these `beginner` and `help-wanted` issues:

* [Beginner issues](https://github.com/search?utf8=%E2%9C%93&q=is%3Aopen+is%3Aissue+label%3Abeginner+label%3Ahelp-wanted+repo%3Ad0p1s4m4%2FFukuro+sort%3Acomments-desc) - issues which should only require a few lines of code, and a test or two.
* [Help wanted issues](https://github.com/search?q=is%3Aopen+is%3Aissue+label%3Ahelp-wanted+repo%3Ad0p1s4m4%2FFukuro+sort%3Acomments-desc+-label%3Abeginner) - issues which should be a bit more involved than `beginner` issues.

Both issue lists are sorted by total number of comments. While not perfect, number of comments is a reasonable proxy for impact a given change will have.

## Styleguides

### Git Commit Message

Git commit message **MUST** follow [Coventional Commits convention](https://www.conventionalcommits.org/en/v1.0.0/)

Other recommandations:
- Use the present tense ("add" instead of "added")
- Use the imperative mood ("move cursor to..." not "moves cursor to...")

### C Coding Style

You **MUST** follow our [coding style](http://style.d0p1.eu)

---

_(This text is based on the [Atom's CONTRIBUTING.md](https://github.com/atom/atom/blob/master/CONTRIBUTING.md))_

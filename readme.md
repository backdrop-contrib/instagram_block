INSTAGRAM BLOCK
===========

CONTENTS OF THIS FILE
---------------------

 - Introduction
 - Requirements
 - Installation
 - Permissions
 - Usage
 - Sponsors

INTRODUCTION
------------

This is a very simple module that integrates with Instagram and creates a block containing your most recent instagram posts.

Each block's configuration page lets you choose how many posts and what size they should appear in the block. The images are individually exposed to the drupal theme layer, so developers have access to an all of the variables provided by the instagram api should they choose to extent the block. For more informations see the instagram developer pages: http://instagram.com/developer/endpoints/users/#get_users_media_recent

This module depends on php curl commands to parse the information from instagram and thus has a dependency on php5-curl.

I also provide an authorisation callback to get the users instagram details through a site that I host (http://instagram.yanniboi.com).

The heavy lifting for this module was done by Nick from Blueprint Interactive, so kudos to him.

TESTED
-----

Created an Instagram user accout block and a hashtag block in Backdrop 1.1


KNOWN ISSUES
---------------------



REQUIREMENTS
------------


INSTALLATION
------------

Instagram Block can be installed via the standard Backdrop installation process
(http://drupal.org/documentation/install/modules-themes/modules-7).

PERMISSIONS
------------

@todo


USAGE
-----

You will need to be logged in to the Instagram account you wish to show if you are setting up the user block.

This module installs two blocks for you to use (as sidebars, etc...)

The config page contains basic authentication config while the blocks on the Layout page contain most of the settings.

License
-------

This project is GPL v2 software. See the LICENSE.txt file in this directory for complete text.

Maintainers
-----------

- seeking

Current Maintainers on Drupal:

 - yanniboi <https://www.drupal.org/u/yanniboi>

Ported to Backdrop by:

 - biolithic <https://github.com/biolithic>

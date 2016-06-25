#CONTENTS OF THIS FILE#

- Introduction
- Requirements
- Recommended modules
- Installation
- Configuration
- Troubleshooting
- FAQ
- Maintainers

##INTRODUCTION##

Social SimpleSharer is a module that creates two blocks. The first block is
intended for full-sized, labeled "share" icons (e.g. Twitter "Tweet"). The
second is for smaller icons. Either one can be styled however you like, but my
initial need was to have icons in a "sticky menu" and other, larger icons in
the masthead.

Also, it's important to note that unlike most other social modules, this one
does not use any Javascript itself (though it does currently require Font
Awesome) - which is increasingly important due to more
blocking at the browser level.

IF this module doesn't meet your needs, you should check out the
"ShareThis" Module
https://www.drupal.org/project/sharethis

That module has more sharing options, and due to its usage of Javascript can
dynamically show click counters.

For a full description of this module, visit the project page:
https://www.drupal.org/project/simplesharer

To submit bug reports and feature suggestions, or to track changes:
https://www.drupal.org/project/issues/

##REQUIREMENTS##

Right now, this module requires either Font Awesome Icons
or the Foundation Icon Font Set to work properly.

Font Awesome is easier as it's accessible using the Font Awesome Icons Module:

- Font Awesome Icons https://www.drupal.org/project/fontawesome

Font Awesome Requires:

- Libraries https://drupal.org/project/libraries
- Font Awesome http://fortawesome.github.com/Font-Awesome/

##RECOMMENDED MODULES##

Currently, no other modules are recommended, but I am looking to move Font
Awesome from REQUIREMENTS to RECOMMENDED MODULES

##INSTALLATION##

Install as you would normally install a contributed Drupal module. See:
   https://drupal.org/documentation/install/modules-themes/modules-7
   for further information.

##CONFIGURATION##

The module is configurable from the Blocks Admin interface. From there, you
can select which blocks you want enabled. Within each of the blocks, you can
choose which of Facebook, Twitter, Tumblr, Pinterest, LinkedIN, or E-mail you
want users to be able to share.

##TROUBLESHOOTING##

If things look wrong, make certain to provide some styles in your theme. I'll
try to have some default CSS files in the module that will be turned on but
can be overridden. These are not available yet.

##FAQ##

Q: Why would I use this instead of another share module?
A: It's simpler, and it doesn't require any Javascript - especially
   oft-blocked 3rd party Javascript. There is also a user-privacy aspect. If
   you aren't collecting user information, there's no reason for you to use
   modules that do either. If you aren't afraid of functionality being
   diminished if 3rd party Javascript is blocked, then there are lots of great
   choices.

Q: Why did you choose the share options that are available?
A: Those are the ones I needed for the current project. If you have others,
   please just submit a patch - or at least make a request for a particular
   sharing service.

##MAINTAINERS##

Current maintainers:

- Elliot Christenson (elliotc) - https://www.drupal.org/u/elliotc

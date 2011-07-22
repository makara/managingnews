$Id$


MANAGING NEWS

A RSS/Atom based news tracker.

FEATURES

- Aggregate RSS/Atom news
- Show news as list or on a map
- Search news
- Bundle interesting news into channels
- Configurable term extraction (auto tagging) - automatically tag incoming items
  with geo terms or plain tags.
- Configurable maps


INSTALLATION AND UPGRADES

Please refer to INSTALL.txt or UPGRADE.txt


CREDITS

Designed and developed by Development Seed.
Built with funding from Knight Foundation.


TRANSLATIONS

To translate the Managing News interface into languages other than English,
follow these steps:

1. Enable the locale module
2. Download and enable the Localization client
   http://drupal.org/project/l10n_client
3. Create a new language at admin/settings/language
4. Configure your language negotiation settings at
   admin/settings/language/configure
5. Switch to your new language. For example, if you enabled Path prefix language
   negotiation, you can browse to http://yousite.com/<language_code>/
6. The l10n client should appear at the bottom of your screen. You may start
   translating the interface.

Note: The l10n client does not always identify every string that requires a
translation. If you encounter a problematic string, you can still translate it
by searching for the string at admin/build/translate/search.

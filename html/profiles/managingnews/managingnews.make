; $Id$

api = 2
core = 6.x

; Contrib projects

projects[boxes][subdir] = "contrib"
projects[boxes][version] = 1.0

projects[context][subdir] = "contrib"
projects[context][version] = 3.0

projects[ctools][subdir] = "contrib"
projects[ctools][version] = 1.7
projects[ctools][patch][] = "http://drupal.org/files/issues/911362-8_D6_plugins_static.patch"
projects[ctools][patch][] = "http://drupal.org/files/issues/911396-1_fix_notice.patch"

projects[data][subdir] = "contrib"
projects[data][version] = 1.0-alpha14
projects[data][patch][] = "http://drupal.org/files/issues/937606_1.patch"

projects[devel][subdir] = "contrib"

projects[designkit][subdir] = "contrib"
projects[designkit][version] = 1.0-beta1

projects[diff][subdir] = "contrib"
projects[diff][version] = 2.1-alpha3

projects[drupal_queue][subdir] = "contrib"
projects[drupal_queue][version] = 1.1

projects[extractor][subdir] = "contrib"
projects[extractor][version] = 1.0-alpha7

projects[features][subdir] = "contrib"
projects[features][version] = 1.0

projects[feeds][subdir] = "contrib"
projects[feeds][version] = 1.0-beta10

projects[flot][subdir] = "contrib"
projects[flot][type] = "module"
projects[flot][download][type] = "cvs"
projects[flot][download][module] = "contributions/modules/flot"
projects[flot][download][revision] = "DRUPAL-6--1:2010-09-07"

projects[geotaxonomy][subdir] = "contrib"
projects[geotaxonomy][version] = 2.0-beta3

projects[imageapi][subdir] = "contrib"
projects[imageapi][version] = 1.8

projects[imagecache][subdir] = "contrib"
projects[imagecache][version] = 2.0-beta10

projects[job_scheduler][subdir] = "contrib"
projects[job_scheduler][version] = 1.0-beta3

projects[jquery_ui][subdir] = "contrib"
projects[jquery_ui][version] = 1.4

projects[kml][subdir] = "contrib"
projects[kml][version] = 2.0-alpha1

projects[libraries][subdir] = "contrib"
projects[libraries][version] = 1.0-alpha1

projects[l10n_client][subdir] = "contrib"
projects[l10n_client][version] = 1.7

projects[mapbox][subdir] = "contrib"
projects[mapbox][version] = 1.0-alpha3

projects[mark][subdir] = "contrib"
projects[mark][version] = 1.0-beta4

projects[openidadmin][subdir] = "contrib"
projects[openidadmin][version] = 1.2

projects[openlayers][subdir] = "contrib"
projects[openlayers][version] = 2.0-alpha10

projects[porterstemmer][subdir] = "contrib"
projects[porterstemmer][version] = 2.6

projects[purl][subdir] = "contrib"
projects[purl][version] = 1.0-beta13

projects[schema][subdir] = "contrib"
projects[schema][version] = 1.7

projects[spaces][subdir] = "contrib"
projects[spaces][version] = 3.0

projects[simpletest][subdir] = "contrib"
projects[simpletest][type] = "module"
projects[simpletest][download][type] = "cvs"
projects[simpletest][download][module] = "contributions/modules/simpletest"
projects[simpletest][download][revision] = "DRUPAL-6--2:2010-09-10"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = 2.0

projects[views][subdir] = "contrib"
projects[views][version] = 2.11

projects[views_rss][subdir] = "contrib"
projects[views_rss][version] = 1.0-beta5

projects[votingapi][subdir] = "contrib"
projects[votingapi][version] = 2.3

projects[web_widgets][subdir] = "contrib"
projects[web_widgets][version] = 1.4

; Custom modules

projects[simpleshare][subdir] = "custom"
projects[simpleshare][location] = "http://code.developmentseed.org/fserver"
projects[simpleshare][version] = 1.0-beta5

projects[stored_views][subdir] = "custom"
projects[stored_views][location] = "http://code.developmentseed.org/fserver"
projects[stored_views][version] = 1.0-beta2

projects[views_modes][subdir] = "custom"
projects[views_modes][location] = "http://code.developmentseed.org/fserver"
projects[views_modes][version] = 1.0-beta5

; Themes

projects[jake][subdir] = "custom"
projects[jake][location] = "http://code.developmentseed.org/fserver"
projects[jake][version] = 1.0-beta15

projects[rubik][download][type] = "get"
projects[rubik][download][url] = "http://code.developmentseed.org/sites/code.developmentseed.org/files/fserver/rubik-6.x-3.0-beta1.tgz"
projects[rubik][directory_name] = "rubik"
projects[rubik][type] = "theme"

projects[tao][download][type] = "get"
projects[tao][download][url] = "http://code.developmentseed.org/sites/code.developmentseed.org/files/fserver/tao-6.x-3.1.tgz"
projects[tao][directory_name] = "tao"
projects[tao][type] = "theme"

; Libraries

libraries[flot][download][type] = "get"
libraries[flot][download][url] = "http://flot.googlecode.com/files/flot-0.6.tar.gz"
libraries[flot][directory_name] = "flot"

libraries[jquery_ui][download][type] = "get"
libraries[jquery_ui][download][url] = "http://jquery-ui.googlecode.com/files/jquery.ui-1.6.zip"
libraries[jquery_ui][directory_name] = "jquery.ui"
libraries[jquery_ui][destination] = "modules/contrib/jquery_ui"

libraries[openlayers][download][type] = "get"
libraries[openlayers][download][url] = "http://nodeload.github.com/developmentseed/openlayers_slim/tarball/v1.8"
libraries[openlayers][directory_name] = "openlayers"

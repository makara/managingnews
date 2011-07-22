core = "6.x"
api = "2"

; Includes ====================================================================

includes[openatrium] = "../html/profiles/managingnews/managingnews.make"

; Override managingnews =======================================================

; Modules =====================================================================

; Libraries ===================================================================

libraries[profiler][download][type] = "file"
libraries[profiler][download][url] = "http://ftp.drupal.org/files/projects/profiler-6.x-2.0-beta2.tar.gz"

libraries[profile_helper][download][type] = "git"
libraries[profile_helper][download][url] = "git://github.com/Wiredcraft/profile_helper.git"
libraries[profile_helper][download][branch] = "6.x"

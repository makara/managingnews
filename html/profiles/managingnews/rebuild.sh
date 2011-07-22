#!/bin/bash
#
# This command expects to be run within the Managing News profile directory. To
# generate a full distribution for you it must be a CVS checkout.
#
# To use this command you must have `drush make`, `cvs` and `git` installed.
#
# Original script by Jeff Miccolis for Open Atrium.
#

if [ -f managingnews.make ]; then
  echo -e "\nThis command can be used to run managingnews.make in place, or to generate"
  echo -e "a complete distribution of Managing News.\n\nWhich would you like?"
  echo "  [1] Rebuild Managing News in place (overwrites any changes!)."
  echo "  [2] Build a full Managing News distribution"
  echo -e "Selection: \c"
  read SELECTION

  if [ $SELECTION = "1" ]; then

    # Run managingnews.make only.
    echo "Building Managing News install profile..."
    rm -Rf modules/ themes/ libraries/
    cvs checkout -d modules -r DRUPAL-6--1 contributions/profiles/managingnews/modules
    drush -y make --working-copy --no-core --contrib-destination=. managingnews.make

  elif [ $SELECTION = "2" ]; then

    # Generate a complete tar.gz of Drupal + Managing News.
    echo "Building Managing News distribution..."

MAKE=$(cat <<EOF
core = "6.x"\n
api = 2\n
projects[drupal][version] = "6.19"\n
projects[managingnews][type] = "profile"\n
projects[managingnews][download][type] = "cvs"\n
projects[managingnews][download][module] = "contributions/profiles/managingnews"\n
projects[managingnews][download][revision] =
EOF
)

    TAG=`cvs status managingnews.make | grep "Sticky Tag:" | awk '{print $3}'`
    if [ -n $TAG ]; then
      if [ $TAG = "(none)" ]; then
        TAG="HEAD"
        VERSION="head"
      elif [ $TAG = "HEAD" ]; then
        VERSION="head"
      else
        # Convert 1-1-BETA6 into 1.1-BETA6
        VERSION=`echo ${TAG:10} | sed s/"\([0-9]\)-\([0-9]\)"/"\1.\2"/`
      fi
      MAKE="$MAKE $TAG\n"
      NAME=`echo "managingnews-$VERSION" | tr '[:upper:]' '[:lower:]'`
      echo -e $MAKE | drush make --yes - $NAME
      zip -r $NAME.zip $NAME
    else
      echo 'Could not determine CVS tag. Is managingnews.make a CVS checkout?'
    fi
  else
   echo "Invalid selection."
  fi
else
  echo 'Could not locate file "managingnews.make"'
fi

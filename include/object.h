




<!DOCTYPE html>
<html>
  <head prefix="og: http://ogp.me/ns# fb: http://ogp.me/ns/fb# object: http://ogp.me/ns/object# article: http://ogp.me/ns/article# profile: http://ogp.me/ns/profile#">
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
        <title>Blobby/include/object.h at master · BlobbyProj/Blobby</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />
    <link rel="apple-touch-icon" sizes="57x57" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="114x114" href="/apple-touch-icon-114.png" />
    <link rel="apple-touch-icon" sizes="72x72" href="/apple-touch-icon-144.png" />
    <link rel="apple-touch-icon" sizes="144x144" href="/apple-touch-icon-144.png" />
    <meta property="fb:app_id" content="1401488693436528"/>

      <meta content="@github" name="twitter:site" /><meta content="summary" name="twitter:card" /><meta content="BlobbyProj/Blobby" name="twitter:title" /><meta content="Blobby - Group Project; a game." name="twitter:description" /><meta content="https://identicons.github.com/8f0cc86d8c3951770e6fd8b10ed0a722.png" name="twitter:image:src" />
<meta content="GitHub" property="og:site_name" /><meta content="object" property="og:type" /><meta content="https://identicons.github.com/8f0cc86d8c3951770e6fd8b10ed0a722.png" property="og:image" /><meta content="BlobbyProj/Blobby" property="og:title" /><meta content="https://github.com/BlobbyProj/Blobby" property="og:url" /><meta content="Blobby - Group Project; a game." property="og:description" />

    <meta name="hostname" content="github-fe123-cp1-prd.iad.github.net">
    <meta name="ruby" content="ruby 2.1.0p0-github-tcmalloc (87d8860372) [x86_64-linux]">
    <link rel="assets" href="https://github.global.ssl.fastly.net/">
    <link rel="conduit-xhr" href="https://ghconduit.com:25035/">
    <link rel="xhr-socket" href="/_sockets" />
    


    <meta name="msapplication-TileImage" content="/windows-tile.png" />
    <meta name="msapplication-TileColor" content="#ffffff" />
    <meta name="selected-link" value="repo_source" data-pjax-transient />
    <meta content="collector.githubapp.com" name="octolytics-host" /><meta content="collector-cdn.github.com" name="octolytics-script-host" /><meta content="github" name="octolytics-app-id" /><meta content="A9E75136:29F3:5C5F2D2:52ED672B" name="octolytics-dimension-request_id" /><meta content="4730232" name="octolytics-actor-id" /><meta content="dmhartsook" name="octolytics-actor-login" /><meta content="f0fb541921090df17afa241229d7ac3ab037485ddd358843c950c5a301592f9f" name="octolytics-actor-hash" />
    

    
    
    <link rel="icon" type="image/x-icon" href="/favicon.ico" />

    <meta content="authenticity_token" name="csrf-param" />
<meta content="x6sSJynJz0bvxjGIm3hdFf5URIOj6bpLSLpgSGyZyyI=" name="csrf-token" />

    <link href="https://github.global.ssl.fastly.net/assets/github-ff4edf09390055458cebc46ef922e61ee1f5fc52.css" media="all" rel="stylesheet" type="text/css" />
    <link href="https://github.global.ssl.fastly.net/assets/github2-09d4cddbd997c7aff84e5b1a25917774ca5c8fd7.css" media="all" rel="stylesheet" type="text/css" />
    


      <script src="https://github.global.ssl.fastly.net/assets/frameworks-02ee5d6f13ffacca6207d163a3c10aba4fb80b16.js" type="text/javascript"></script>
      <script async="async" defer="defer" src="https://github.global.ssl.fastly.net/assets/github-ddf95c725e6956db29688761f8bd21b3a2961168.js" type="text/javascript"></script>
      
      <meta http-equiv="x-pjax-version" content="91108283203ecd1f2ae6589c4e82de7c">

        <link data-pjax-transient rel='permalink' href='/BlobbyProj/Blobby/blob/3a84aec87eeb12c73971d36bb057b4a275e35483/include/object.h'>

  <meta name="description" content="Blobby - Group Project; a game." />

  <meta content="6405642" name="octolytics-dimension-user_id" /><meta content="BlobbyProj" name="octolytics-dimension-user_login" /><meta content="15923274" name="octolytics-dimension-repository_id" /><meta content="BlobbyProj/Blobby" name="octolytics-dimension-repository_nwo" /><meta content="true" name="octolytics-dimension-repository_public" /><meta content="false" name="octolytics-dimension-repository_is_fork" /><meta content="15923274" name="octolytics-dimension-repository_network_root_id" /><meta content="BlobbyProj/Blobby" name="octolytics-dimension-repository_network_root_nwo" />
  <link href="https://github.com/BlobbyProj/Blobby/commits/master.atom" rel="alternate" title="Recent Commits to Blobby:master" type="application/atom+xml" />

  </head>


  <body class="logged_in  env-production macintosh vis-public page-blob">
    <div class="wrapper">
      
      
      
      


      <div class="header header-logged-in true">
  <div class="container clearfix">

    <a class="header-logo-invertocat" href="https://github.com/organizations/BlobbyProj">
  <span class="mega-octicon octicon-mark-github"></span>
</a>

    
    <a href="/notifications" class="notification-indicator tooltipped downwards" data-gotokey="n" title="You have no unread notifications">
        <span class="mail-status all-read"></span>
</a>

      <div class="command-bar js-command-bar  in-repository">
          <form accept-charset="UTF-8" action="/search" class="command-bar-form" id="top_search_form" method="get">

<input type="text" data-hotkey="/ s" name="q" id="js-command-bar-field" placeholder="Search or type a command" tabindex="1" autocapitalize="off"
    
    data-username="dmhartsook"
      data-repo="BlobbyProj/Blobby"
      data-branch="master"
      data-sha="c5adf6e5fc4cb4f49b2899a837588f13cea0a3f2"
  >

    <input type="hidden" name="nwo" value="BlobbyProj/Blobby" />

    <div class="select-menu js-menu-container js-select-menu search-context-select-menu">
      <span class="minibutton select-menu-button js-menu-target">
        <span class="js-select-button">This repository</span>
      </span>

      <div class="select-menu-modal-holder js-menu-content js-navigation-container">
        <div class="select-menu-modal">

          <div class="select-menu-item js-navigation-item js-this-repository-navigation-item selected">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" class="js-search-this-repository" name="search_target" value="repository" checked="checked" />
            <div class="select-menu-item-text js-select-button-text">This repository</div>
          </div> <!-- /.select-menu-item -->

          <div class="select-menu-item js-navigation-item js-all-repositories-navigation-item">
            <span class="select-menu-item-icon octicon octicon-check"></span>
            <input type="radio" name="search_target" value="global" />
            <div class="select-menu-item-text js-select-button-text">All repositories</div>
          </div> <!-- /.select-menu-item -->

        </div>
      </div>
    </div>

  <span class="octicon help tooltipped downwards" title="Show command bar help">
    <span class="octicon octicon-question"></span>
  </span>


  <input type="hidden" name="ref" value="cmdform">

</form>
        <ul class="top-nav">
          <li class="explore"><a href="/explore">Explore</a></li>
            <li><a href="https://gist.github.com">Gist</a></li>
            <li><a href="/blog">Blog</a></li>
          <li><a href="https://help.github.com">Help</a></li>
        </ul>
      </div>

    


  <ul id="user-links">
    <li>
      <a href="/dmhartsook" class="name">
        <img alt="dmhartsook" height="20" src="https://1.gravatar.com/avatar/3ade02cf51a2916e64e7720073e3e2a4?d=https%3A%2F%2Fidenticons.github.com%2Fe2b042e842f9fa1fe90acbc16a7fdca4.png&amp;r=x&amp;s=140" width="20" /> dmhartsook
      </a>
    </li>

    <li class="new-menu dropdown-toggle js-menu-container">
      <a href="#" class="js-menu-target tooltipped downwards" title="Create new..." aria-label="Create new...">
        <span class="octicon octicon-plus"></span>
        <span class="dropdown-arrow"></span>
      </a>

      <div class="js-menu-content">
      </div>
    </li>

    <li>
      <a href="/settings/profile" id="account_settings"
        class="tooltipped downwards"
        aria-label="Account settings "
        title="Account settings ">
        <span class="octicon octicon-tools"></span>
      </a>
    </li>
    <li>
      <a class="tooltipped downwards" href="/logout" data-method="post" id="logout" title="Sign out" aria-label="Sign out">
        <span class="octicon octicon-log-out"></span>
      </a>
    </li>

  </ul>

<div class="js-new-dropdown-contents hidden">
  

<ul class="dropdown-menu">
  <li>
    <a href="/new"><span class="octicon octicon-repo-create"></span> New repository</a>
  </li>
  <li>
    <a href="/organizations/new"><span class="octicon octicon-organization"></span> New organization</a>
  </li>
    <li class="section-title">
      <span title="BlobbyProj">This organization</span>
    </li>
      <li>
        <a href="/orgs/BlobbyProj/members/new"><span class="octicon octicon-person-add"></span> New member</a>
      </li>
    <li>
      <a href="/orgs/BlobbyProj/new-team"><span class="octicon octicon-jersey"></span> New team</a>
    </li>
    <li>
      <a href="/organizations/BlobbyProj/repositories/new"><span class="octicon octicon-repo-create"></span> New repository</a>
    </li>


    <li class="section-title">
      <span title="BlobbyProj/Blobby">This repository</span>
    </li>
      <li>
        <a href="/BlobbyProj/Blobby/issues/new"><span class="octicon octicon-issue-opened"></span> New issue</a>
      </li>
      <li>
        <a href="/BlobbyProj/Blobby/settings/collaboration"><span class="octicon octicon-person-add"></span> New collaborator</a>
      </li>
</ul>

</div>


    
  </div>
</div>

      

      




          <div class="site" itemscope itemtype="http://schema.org/WebPage">
    
    <div class="pagehead repohead instapaper_ignore readability-menu">
      <div class="container">
        

<ul class="pagehead-actions">

    <li class="subscription">
      <form accept-charset="UTF-8" action="/notifications/subscribe" class="js-social-container" data-autosubmit="true" data-remote="true" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="x6sSJynJz0bvxjGIm3hdFf5URIOj6bpLSLpgSGyZyyI=" /></div>  <input id="repository_id" name="repository_id" type="hidden" value="15923274" />

    <div class="select-menu js-menu-container js-select-menu">
      <a class="social-count js-social-count" href="/BlobbyProj/Blobby/watchers">
        3
      </a>
      <span class="minibutton select-menu-button with-count js-menu-target" role="button" tabindex="0">
        <span class="js-select-button">
          <span class="octicon octicon-eye-unwatch"></span>
          Unwatch
        </span>
      </span>

      <div class="select-menu-modal-holder">
        <div class="select-menu-modal subscription-menu-modal js-menu-content">
          <div class="select-menu-header">
            <span class="select-menu-title">Notification status</span>
            <span class="octicon octicon-remove-close js-menu-close"></span>
          </div> <!-- /.select-menu-header -->

          <div class="select-menu-list js-navigation-container" role="menu">

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_included" name="do" type="radio" value="included" />
                <h4>Not watching</h4>
                <span class="description">You only receive notifications for conversations in which you participate or are @mentioned.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye-watch"></span>
                  Watch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item selected" role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input checked="checked" id="do_subscribed" name="do" type="radio" value="subscribed" />
                <h4>Watching</h4>
                <span class="description">You receive notifications for all conversations in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-eye-unwatch"></span>
                  Unwatch
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

            <div class="select-menu-item js-navigation-item " role="menuitem" tabindex="0">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <div class="select-menu-item-text">
                <input id="do_ignore" name="do" type="radio" value="ignore" />
                <h4>Ignoring</h4>
                <span class="description">You do not receive any notifications for conversations in this repository.</span>
                <span class="js-select-button-text hidden-select-button-text">
                  <span class="octicon octicon-mute"></span>
                  Stop ignoring
                </span>
              </div>
            </div> <!-- /.select-menu-item -->

          </div> <!-- /.select-menu-list -->

        </div> <!-- /.select-menu-modal -->
      </div> <!-- /.select-menu-modal-holder -->
    </div> <!-- /.select-menu -->

</form>
    </li>

  <li>
  

  <div class="js-toggler-container js-social-container starring-container ">
    <a href="/BlobbyProj/Blobby/unstar"
      class="minibutton with-count js-toggler-target star-button starred upwards"
      title="Unstar this repository" data-remote="true" data-method="post" rel="nofollow">
      <span class="octicon octicon-star-delete"></span><span class="text">Unstar</span>
    </a>

    <a href="/BlobbyProj/Blobby/star"
      class="minibutton with-count js-toggler-target star-button unstarred upwards"
      title="Star this repository" data-remote="true" data-method="post" rel="nofollow">
      <span class="octicon octicon-star"></span><span class="text">Star</span>
    </a>

      <a class="social-count js-social-count" href="/BlobbyProj/Blobby/stargazers">
        0
      </a>
  </div>

  </li>


        <li>
          <a href="/BlobbyProj/Blobby/fork" class="minibutton with-count js-toggler-target fork-button lighter upwards" title="Fork this repo" rel="facebox nofollow">
            <span class="octicon octicon-git-branch-create"></span><span class="text">Fork</span>
          </a>
          <a href="/BlobbyProj/Blobby/network" class="social-count">0</a>
        </li>


</ul>

        <h1 itemscope itemtype="http://data-vocabulary.org/Breadcrumb" class="entry-title public">
          <span class="repo-label"><span>public</span></span>
          <span class="mega-octicon octicon-repo"></span>
          <span class="author">
            <a href="/BlobbyProj" class="url fn" itemprop="url" rel="author"><span itemprop="title">BlobbyProj</span></a>
          </span>
          <span class="repohead-name-divider">/</span>
          <strong><a href="/BlobbyProj/Blobby" class="js-current-repository js-repo-home-link">Blobby</a></strong>

          <span class="page-context-loader">
            <img alt="Octocat-spinner-32" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
          </span>

        </h1>
      </div><!-- /.container -->
    </div><!-- /.repohead -->

    <div class="container">
      

      <div class="repository-with-sidebar repo-container new-discussion-timeline js-new-discussion-timeline  ">
        <div class="repository-sidebar">
            

<div class="sunken-menu vertical-right repo-nav js-repo-nav js-repository-container-pjax js-octicon-loaders">
  <div class="sunken-menu-contents">
    <ul class="sunken-menu-group">
      <li class="tooltipped leftwards" title="Code">
        <a href="/BlobbyProj/Blobby" aria-label="Code" class="selected js-selected-navigation-item sunken-menu-item" data-gotokey="c" data-pjax="true" data-selected-links="repo_source repo_downloads repo_commits repo_tags repo_branches /BlobbyProj/Blobby">
          <span class="octicon octicon-code"></span> <span class="full-word">Code</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

        <li class="tooltipped leftwards" title="Issues">
          <a href="/BlobbyProj/Blobby/issues" aria-label="Issues" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-gotokey="i" data-selected-links="repo_issues /BlobbyProj/Blobby/issues">
            <span class="octicon octicon-issue-opened"></span> <span class="full-word">Issues</span>
            <span class='counter'>0</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>

      <li class="tooltipped leftwards" title="Pull Requests">
        <a href="/BlobbyProj/Blobby/pulls" aria-label="Pull Requests" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-gotokey="p" data-selected-links="repo_pulls /BlobbyProj/Blobby/pulls">
            <span class="octicon octicon-git-pull-request"></span> <span class="full-word">Pull Requests</span>
            <span class='counter'>0</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>


        <li class="tooltipped leftwards" title="Wiki">
          <a href="/BlobbyProj/Blobby/wiki" aria-label="Wiki" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_wiki /BlobbyProj/Blobby/wiki">
            <span class="octicon octicon-book"></span> <span class="full-word">Wiki</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>        </li>
    </ul>
    <div class="sunken-menu-separator"></div>
    <ul class="sunken-menu-group">

      <li class="tooltipped leftwards" title="Pulse">
        <a href="/BlobbyProj/Blobby/pulse" aria-label="Pulse" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="pulse /BlobbyProj/Blobby/pulse">
          <span class="octicon octicon-pulse"></span> <span class="full-word">Pulse</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped leftwards" title="Graphs">
        <a href="/BlobbyProj/Blobby/graphs" aria-label="Graphs" class="js-selected-navigation-item sunken-menu-item" data-pjax="true" data-selected-links="repo_graphs repo_contributors /BlobbyProj/Blobby/graphs">
          <span class="octicon octicon-graph"></span> <span class="full-word">Graphs</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>

      <li class="tooltipped leftwards" title="Network">
        <a href="/BlobbyProj/Blobby/network" aria-label="Network" class="js-selected-navigation-item sunken-menu-item js-disable-pjax" data-selected-links="repo_network /BlobbyProj/Blobby/network">
          <span class="octicon octicon-git-branch"></span> <span class="full-word">Network</span>
          <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
</a>      </li>
    </ul>


      <div class="sunken-menu-separator"></div>
      <ul class="sunken-menu-group">
        <li class="tooltipped leftwards" title="Settings">
          <a href="/BlobbyProj/Blobby/settings"
            class="sunken-menu-item" data-pjax aria-label="Settings">
            <span class="octicon octicon-tools"></span> <span class="full-word">Settings</span>
            <img alt="Octocat-spinner-32" class="mini-loader" height="16" src="https://github.global.ssl.fastly.net/images/spinners/octocat-spinner-32.gif" width="16" />
          </a>
        </li>
      </ul>
  </div>
</div>

              <div class="only-with-full-nav">
                

  

<div class="clone-url "
  data-protocol-type="http"
  data-url="/users/set_protocol?protocol_selector=http&amp;protocol_type=push">
  <h3><strong>HTTPS</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/BlobbyProj/Blobby.git" readonly="readonly">

    <span class="js-zeroclipboard url-box-clippy minibutton zeroclipboard-button" data-clipboard-text="https://github.com/BlobbyProj/Blobby.git" data-copied-hint="copied!" title="copy to clipboard"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>

  

<div class="clone-url open"
  data-protocol-type="ssh"
  data-url="/users/set_protocol?protocol_selector=ssh&amp;protocol_type=push">
  <h3><strong>SSH</strong> clone URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="git@github.com:BlobbyProj/Blobby.git" readonly="readonly">

    <span class="js-zeroclipboard url-box-clippy minibutton zeroclipboard-button" data-clipboard-text="git@github.com:BlobbyProj/Blobby.git" data-copied-hint="copied!" title="copy to clipboard"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>

  

<div class="clone-url "
  data-protocol-type="subversion"
  data-url="/users/set_protocol?protocol_selector=subversion&amp;protocol_type=push">
  <h3><strong>Subversion</strong> checkout URL</h3>
  <div class="clone-url-box">
    <input type="text" class="clone js-url-field"
           value="https://github.com/BlobbyProj/Blobby" readonly="readonly">

    <span class="js-zeroclipboard url-box-clippy minibutton zeroclipboard-button" data-clipboard-text="https://github.com/BlobbyProj/Blobby" data-copied-hint="copied!" title="copy to clipboard"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>


<p class="clone-options">You can clone with
      <a href="#" class="js-clone-selector" data-protocol="http">HTTPS</a>,
      <a href="#" class="js-clone-selector" data-protocol="ssh">SSH</a>,
      or <a href="#" class="js-clone-selector" data-protocol="subversion">Subversion</a>.
  <span class="octicon help tooltipped upwards" title="Get help on which URL is right for you.">
    <a href="https://help.github.com/articles/which-remote-url-should-i-use">
    <span class="octicon octicon-question"></span>
    </a>
  </span>
</p>

  <a href="http://mac.github.com" data-url="github-mac://openRepo/https://github.com/BlobbyProj/Blobby" class="minibutton sidebar-button js-conduit-rewrite-url">
    <span class="octicon octicon-device-desktop"></span>
    Clone in Desktop
  </a>


                <a href="/BlobbyProj/Blobby/archive/master.zip"
                   class="minibutton sidebar-button"
                   title="Download this repository as a zip file"
                   rel="nofollow">
                  <span class="octicon octicon-cloud-download"></span>
                  Download ZIP
                </a>
              </div>
        </div><!-- /.repository-sidebar -->

        <div id="js-repo-pjax-container" class="repository-content context-loader-container" data-pjax-container>
          


<!-- blob contrib key: blob_contributors:v21:7e2ced50f00456e3b76b480593c93d48 -->

<p title="This is a placeholder element" class="js-history-link-replace hidden"></p>

<a href="/BlobbyProj/Blobby/find/master" data-pjax data-hotkey="t" class="js-show-file-finder" style="display:none">Show File Finder</a>

<div class="file-navigation">
  

<div class="select-menu js-menu-container js-select-menu" >
  <span class="minibutton select-menu-button js-menu-target" data-hotkey="w"
    data-master-branch="master"
    data-ref="master"
    role="button" aria-label="Switch branches or tags" tabindex="0">
    <span class="octicon octicon-git-branch"></span>
    <i>branch:</i>
    <span class="js-select-button">master</span>
  </span>

  <div class="select-menu-modal-holder js-menu-content js-navigation-container" data-pjax>

    <div class="select-menu-modal">
      <div class="select-menu-header">
        <span class="select-menu-title">Switch branches/tags</span>
        <span class="octicon octicon-remove-close js-menu-close"></span>
      </div> <!-- /.select-menu-header -->

      <div class="select-menu-filters">
        <div class="select-menu-text-filter">
          <input type="text" aria-label="Find or create a branch…" id="context-commitish-filter-field" class="js-filterable-field js-navigation-enable" placeholder="Find or create a branch…">
        </div>
        <div class="select-menu-tabs">
          <ul>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="branches" class="js-select-menu-tab">Branches</a>
            </li>
            <li class="select-menu-tab">
              <a href="#" data-tab-filter="tags" class="js-select-menu-tab">Tags</a>
            </li>
          </ul>
        </div><!-- /.select-menu-tabs -->
      </div><!-- /.select-menu-filters -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="branches">

        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/BlobbyProj/Blobby/blob/deanna/include/object.h"
                 data-name="deanna"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="deanna">deanna</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/BlobbyProj/Blobby/blob/katya2/include/object.h"
                 data-name="katya2"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="katya2">katya2</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item selected">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/BlobbyProj/Blobby/blob/master/include/object.h"
                 data-name="master"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="master">master</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/BlobbyProj/Blobby/blob/natasha/include/object.h"
                 data-name="natasha"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="natasha">natasha</a>
            </div> <!-- /.select-menu-item -->
            <div class="select-menu-item js-navigation-item ">
              <span class="select-menu-item-icon octicon octicon-check"></span>
              <a href="/BlobbyProj/Blobby/blob/sam/include/object.h"
                 data-name="sam"
                 data-skip-pjax="true"
                 rel="nofollow"
                 class="js-navigation-open select-menu-item-text js-select-button-text css-truncate-target"
                 title="sam">sam</a>
            </div> <!-- /.select-menu-item -->
        </div>

          <form accept-charset="UTF-8" action="/BlobbyProj/Blobby/branches" class="js-create-branch select-menu-item select-menu-new-item-form js-navigation-item js-new-item-form" method="post"><div style="margin:0;padding:0;display:inline"><input name="authenticity_token" type="hidden" value="x6sSJynJz0bvxjGIm3hdFf5URIOj6bpLSLpgSGyZyyI=" /></div>
            <span class="octicon octicon-git-branch-create select-menu-item-icon"></span>
            <div class="select-menu-item-text">
              <h4>Create branch: <span class="js-new-item-name"></span></h4>
              <span class="description">from ‘master’</span>
            </div>
            <input type="hidden" name="name" id="name" class="js-new-item-value">
            <input type="hidden" name="branch" id="branch" value="master" />
            <input type="hidden" name="path" id="path" value="include/object.h" />
          </form> <!-- /.select-menu-item -->

      </div> <!-- /.select-menu-list -->

      <div class="select-menu-list select-menu-tab-bucket js-select-menu-tab-bucket" data-tab-filter="tags">
        <div data-filterable-for="context-commitish-filter-field" data-filterable-type="substring">


        </div>

        <div class="select-menu-no-results">Nothing to show</div>
      </div> <!-- /.select-menu-list -->

    </div> <!-- /.select-menu-modal -->
  </div> <!-- /.select-menu-modal-holder -->
</div> <!-- /.select-menu -->

  <div class="breadcrumb">
    <span class='repo-root js-repo-root'><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/BlobbyProj/Blobby" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">Blobby</span></a></span></span><span class="separator"> / </span><span itemscope="" itemtype="http://data-vocabulary.org/Breadcrumb"><a href="/BlobbyProj/Blobby/tree/master/include" data-branch="master" data-direction="back" data-pjax="true" itemscope="url"><span itemprop="title">include</span></a></span><span class="separator"> / </span><strong class="final-path">object.h</strong> <span class="js-zeroclipboard minibutton zeroclipboard-button" data-clipboard-text="include/object.h" data-copied-hint="copied!" title="copy to clipboard"><span class="octicon octicon-clippy"></span></span>
  </div>
</div>


  <div class="commit file-history-tease">
    <img alt="heinzsamuel" class="main-avatar" height="24" src="https://0.gravatar.com/avatar/1f10937d8fd6f130514dd778ea3539d0?d=https%3A%2F%2Fidenticons.github.com%2F52b975d3aaa5b421b41c122b3fe1f879.png&amp;r=x&amp;s=140" width="24" />
    <span class="author"><a href="/heinzsamuel" rel="author">heinzsamuel</a></span>
    <time class="js-relative-date" datetime="2014-02-01T13:26:32-08:00" title="2014-02-01 13:26:32">February 01, 2014</time>
    <div class="commit-title">
        <a href="/BlobbyProj/Blobby/commit/3a84aec87eeb12c73971d36bb057b4a275e35483" class="message" data-pjax="true" title="Rectangle Class properly updated

It is updated on each step and can be returned from  a getter.">Rectangle Class properly updated</a>
    </div>

    <div class="participation">
      <p class="quickstat"><a href="#blob_contributors_box" rel="facebox"><strong>2</strong> contributors</a></p>
          <a class="avatar tooltipped downwards" title="heinzsamuel" href="/BlobbyProj/Blobby/commits/master/include/object.h?author=heinzsamuel"><img alt="heinzsamuel" height="20" src="https://0.gravatar.com/avatar/1f10937d8fd6f130514dd778ea3539d0?d=https%3A%2F%2Fidenticons.github.com%2F52b975d3aaa5b421b41c122b3fe1f879.png&amp;r=x&amp;s=140" width="20" /></a>
    <a class="avatar tooltipped downwards" title="dmhartsook" href="/BlobbyProj/Blobby/commits/master/include/object.h?author=dmhartsook"><img alt="dmhartsook" height="20" src="https://1.gravatar.com/avatar/3ade02cf51a2916e64e7720073e3e2a4?d=https%3A%2F%2Fidenticons.github.com%2Fe2b042e842f9fa1fe90acbc16a7fdca4.png&amp;r=x&amp;s=140" width="20" /></a>


    </div>
    <div id="blob_contributors_box" style="display:none">
      <h2 class="facebox-header">Users who have contributed to this file</h2>
      <ul class="facebox-user-list">
          <li class="facebox-user-list-item">
            <img alt="heinzsamuel" height="24" src="https://0.gravatar.com/avatar/1f10937d8fd6f130514dd778ea3539d0?d=https%3A%2F%2Fidenticons.github.com%2F52b975d3aaa5b421b41c122b3fe1f879.png&amp;r=x&amp;s=140" width="24" />
            <a href="/heinzsamuel">heinzsamuel</a>
          </li>
          <li class="facebox-user-list-item">
            <img alt="dmhartsook" height="24" src="https://1.gravatar.com/avatar/3ade02cf51a2916e64e7720073e3e2a4?d=https%3A%2F%2Fidenticons.github.com%2Fe2b042e842f9fa1fe90acbc16a7fdca4.png&amp;r=x&amp;s=140" width="24" />
            <a href="/dmhartsook">dmhartsook</a>
          </li>
      </ul>
    </div>
  </div>

<div id="files" class="bubble">
  <div class="file">
    <div class="meta">
      <div class="info">
        <span class="icon"><b class="octicon octicon-file-text"></b></span>
        <span class="mode" title="File Mode">file</span>
          <span>45 lines (37 sloc)</span>
        <span>0.994 kb</span>
      </div>
      <div class="actions">
        <div class="button-group">
            <a class="minibutton tooltipped leftwards js-conduit-openfile-check"
               href="http://mac.github.com"
               data-url="github-mac://openRepo/https://github.com/BlobbyProj/Blobby?branch=master&amp;filepath=include%2Fobject.h"
               title="Open this file in GitHub for Mac"
               data-failed-title="Your version of GitHub for Mac is too old to open this file. Try checking for updates.">
                <span class="octicon octicon-device-desktop"></span> Open
            </a>
                <a class="minibutton js-update-url-with-hash"
                   href="/BlobbyProj/Blobby/edit/master/include/object.h"
                   data-method="post" rel="nofollow" data-hotkey="e">Edit</a>
          <a href="/BlobbyProj/Blobby/raw/master/include/object.h" class="button minibutton " id="raw-url">Raw</a>
            <a href="/BlobbyProj/Blobby/blame/master/include/object.h" class="button minibutton js-update-url-with-hash">Blame</a>
          <a href="/BlobbyProj/Blobby/commits/master/include/object.h" class="button minibutton " rel="nofollow">History</a>
        </div><!-- /.button-group -->
          <a class="minibutton danger empty-icon tooltipped downwards"
             href="/BlobbyProj/Blobby/delete/master/include/object.h"
             title=""
             data-method="post" data-test-id="delete-blob-file" rel="nofollow">
          Delete
        </a>
      </div><!-- /.actions -->
    </div>
        <div class="blob-wrapper data type-c js-blob-data">
        <table class="file-code file-diff tab-size-8">
          <tr class="file-code-line">
            <td class="blob-line-nums">
              <span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>

            </td>
            <td class="blob-line-code"><div class="code-body highlight"><pre><div class='line' id='LC1'><span class="cp">#ifndef OBJECT_H</span></div><div class='line' id='LC2'><span class="cp">#define OBJECT_H</span></div><div class='line' id='LC3'><br/></div><div class='line' id='LC4'><span class="cp">#include &lt;string&gt;</span></div><div class='line' id='LC5'><span class="cp">#include &quot;globals.h&quot;</span></div><div class='line' id='LC6'><span class="cp">#include &quot;screenmanager.h&quot;</span></div><div class='line' id='LC7'><span class="cp">#include &quot;point.h&quot;</span></div><div class='line' id='LC8'><span class="cp">#include &quot;rectangle.h&quot;</span></div><div class='line' id='LC9'><br/></div><div class='line' id='LC10'><span class="k">class</span> <span class="nc">Object</span> <span class="p">{</span></div><div class='line' id='LC11'>	<span class="nl">protected:</span></div><div class='line' id='LC12'>		<span class="n">Point</span> <span class="n">position</span><span class="p">;</span></div><div class='line' id='LC13'>		<span class="n">Rectangle</span> <span class="n">bound</span><span class="p">;</span></div><div class='line' id='LC14'>		<span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">oid</span><span class="p">;</span></div><div class='line' id='LC15'>		<span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="o">*</span><span class="n">filenames</span><span class="p">;</span></div><div class='line' id='LC16'>		<span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">num_keys</span><span class="p">;</span></div><div class='line' id='LC17'>		<span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">*</span><span class="n">keys</span><span class="p">;</span></div><div class='line' id='LC18'>		<span class="kt">int</span> <span class="n">width</span><span class="p">;</span></div><div class='line' id='LC19'>		<span class="kt">int</span> <span class="n">height</span><span class="p">;</span></div><div class='line' id='LC20'>		<span class="kt">bool</span> <span class="n">loaded</span><span class="p">;</span></div><div class='line' id='LC21'>		<span class="kt">bool</span> <span class="n">visible</span><span class="p">;</span></div><div class='line' id='LC22'>		<span class="kt">bool</span> <span class="n">solid</span><span class="p">;</span></div><div class='line' id='LC23'><br/></div><div class='line' id='LC24'>	<span class="nl">public:</span></div><div class='line' id='LC25'>		<span class="n">Object</span><span class="p">()</span> <span class="o">:</span> <span class="n">width</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">height</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">loaded</span><span class="p">(</span><span class="mi">0</span><span class="p">),</span> <span class="n">visible</span><span class="p">(</span><span class="mi">1</span><span class="p">),</span> <span class="n">solid</span><span class="p">(</span><span class="mi">0</span><span class="p">)</span> <span class="p">{};</span></div><div class='line' id='LC26'>		<span class="k">virtual</span> <span class="o">~</span><span class="n">Object</span><span class="p">()</span> <span class="p">{};</span></div><div class='line' id='LC27'><br/></div><div class='line' id='LC28'>		<span class="kt">double</span> <span class="nf">get_x</span><span class="p">()</span> <span class="p">{</span> <span class="k">return</span> <span class="n">position</span><span class="p">.</span><span class="n">x</span><span class="p">;</span> <span class="p">}</span></div><div class='line' id='LC29'>		<span class="kt">double</span> <span class="nf">get_y</span><span class="p">()</span> <span class="p">{</span> <span class="k">return</span> <span class="n">position</span><span class="p">.</span><span class="n">y</span><span class="p">;</span> <span class="p">}</span></div><div class='line' id='LC30'>		<span class="n">Rectangle</span> <span class="nf">get_bound</span><span class="p">()</span> <span class="p">{</span> <span class="k">return</span> <span class="n">bound</span><span class="p">;</span> <span class="p">}</span></div><div class='line' id='LC31'>		<span class="n">std</span><span class="o">::</span><span class="n">string</span> <span class="o">*</span><span class="n">get_filenames</span><span class="p">()</span> <span class="p">{</span> <span class="k">return</span> <span class="n">filenames</span><span class="p">;</span> <span class="p">}</span></div><div class='line' id='LC32'>		<span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">get_num_keys</span><span class="p">()</span> <span class="p">{</span> <span class="k">return</span> <span class="p">(</span><span class="n">num_keys</span><span class="o">*</span><span class="n">loaded</span><span class="p">);</span> <span class="p">}</span></div><div class='line' id='LC33'>		<span class="kt">unsigned</span> <span class="kt">int</span> <span class="o">*</span><span class="n">get_keys</span><span class="p">()</span> <span class="p">{</span> <span class="k">return</span> <span class="n">keys</span><span class="p">;</span> <span class="p">}</span>	</div><div class='line' id='LC34'>		<span class="kt">bool</span> <span class="n">get_visible</span><span class="p">()</span> <span class="p">{</span> <span class="k">return</span> <span class="n">visible</span><span class="p">;</span> <span class="p">}</span></div><div class='line' id='LC35'><br/></div><div class='line' id='LC36'>		<span class="kt">void</span> <span class="n">set_oid</span><span class="p">(</span><span class="kt">unsigned</span> <span class="kt">int</span> <span class="n">val</span><span class="p">)</span> <span class="p">{</span> <span class="n">oid</span> <span class="o">=</span> <span class="n">val</span><span class="p">;</span> <span class="p">}</span></div><div class='line' id='LC37'><br/></div><div class='line' id='LC38'>		<span class="k">virtual</span> <span class="kt">void</span> <span class="n">step</span><span class="p">()</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC39'>		<span class="k">virtual</span> <span class="kt">void</span> <span class="n">events</span><span class="p">(</span><span class="n">SDL_Event</span> <span class="o">*</span><span class="n">event</span><span class="p">)</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC40'>		<span class="k">virtual</span> <span class="kt">void</span> <span class="n">draw</span><span class="p">()</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC41'>		<span class="k">virtual</span> <span class="kt">void</span> <span class="n">load_surfaces</span><span class="p">()</span><span class="o">=</span><span class="mi">0</span><span class="p">;</span></div><div class='line' id='LC42'><span class="p">};</span></div><div class='line' id='LC43'><br/></div><div class='line' id='LC44'><span class="cp">#endif</span></div></pre></div></td>
          </tr>
        </table>
  </div>

  </div>
</div>

<a href="#jump-to-line" rel="facebox[.linejump]" data-hotkey="l" class="js-jump-to-line" style="display:none">Jump to Line</a>
<div id="jump-to-line" style="display:none">
  <form accept-charset="UTF-8" class="js-jump-to-line-form">
    <input class="linejump-input js-jump-to-line-field" type="text" placeholder="Jump to line&hellip;" autofocus>
    <button type="submit" class="button">Go</button>
  </form>
</div>

        </div>

      </div><!-- /.repo-container -->
      <div class="modal-backdrop"></div>
    </div><!-- /.container -->
  </div><!-- /.site -->


    </div><!-- /.wrapper -->

      <div class="container">
  <div class="site-footer">
    <ul class="site-footer-links right">
      <li><a href="https://status.github.com/">Status</a></li>
      <li><a href="http://developer.github.com">API</a></li>
      <li><a href="http://training.github.com">Training</a></li>
      <li><a href="http://shop.github.com">Shop</a></li>
      <li><a href="/blog">Blog</a></li>
      <li><a href="/about">About</a></li>

    </ul>

    <a href="/">
      <span class="mega-octicon octicon-mark-github" title="GitHub"></span>
    </a>

    <ul class="site-footer-links">
      <li>&copy; 2014 <span title="0.04111s from github-fe123-cp1-prd.iad.github.net">GitHub</span>, Inc.</li>
        <li><a href="/site/terms">Terms</a></li>
        <li><a href="/site/privacy">Privacy</a></li>
        <li><a href="/security">Security</a></li>
        <li><a href="/contact">Contact</a></li>
    </ul>
  </div><!-- /.site-footer -->
</div><!-- /.container -->


    <div class="fullscreen-overlay js-fullscreen-overlay" id="fullscreen_overlay">
  <div class="fullscreen-container js-fullscreen-container">
    <div class="textarea-wrap">
      <textarea name="fullscreen-contents" id="fullscreen-contents" class="js-fullscreen-contents" placeholder="" data-suggester="fullscreen_suggester"></textarea>
          <div class="suggester-container">
              <div class="suggester fullscreen-suggester js-navigation-container" id="fullscreen_suggester"
                 data-url="/BlobbyProj/Blobby/suggestions/commit">
              </div>
          </div>
    </div>
  </div>
  <div class="fullscreen-sidebar">
    <a href="#" class="exit-fullscreen js-exit-fullscreen tooltipped leftwards" title="Exit Zen Mode">
      <span class="mega-octicon octicon-screen-normal"></span>
    </a>
    <a href="#" class="theme-switcher js-theme-switcher tooltipped leftwards"
      title="Switch themes">
      <span class="octicon octicon-color-mode"></span>
    </a>
  </div>
</div>



    <div id="ajax-error-message" class="flash flash-error">
      <span class="octicon octicon-alert"></span>
      <a href="#" class="octicon octicon-remove-close close js-ajax-error-dismiss"></a>
      Something went wrong with that request. Please try again.
    </div>

  </body>
</html>


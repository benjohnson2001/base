Name:		inkscape
Summary:	A Vector Drawing Application
Version:	0.36
Release:	CVS
Copyright:	GPL
Group:		Applications/Graphics
Source:		inkscape-%{version}.tar.gz
URL:		http://inkscape.sourceforge.net/
Prefix:		%{_prefix}
Packager:	Automatic
Vendor:		%{packager}
BuildRoot:	%{_tmppath}/%{name}-%{version}-root

%description
Inkscape is a SVG based generic vector-drawing program for Linux/Unix/Windows.

%prep
%setup

%build
### Needed for snapshot releases.
MYCFLAGS="$RPM_OPT_FLAGS"

if [ ! -x configure ]; then
  CFLAGS="$MYCFLAGS" ./autogen.sh $MYARCH_FLAGS --prefix=%{_prefix} --localstatedir=%{_localstatedir} --sysconfdir=%{_sysconfdir}
else
  %configure 
fi
make

%install
rm -rf %{buildroot}
%makeinstall

%clean
rm -rf %{buildroot}

%files
%defattr(-, root, root)
%doc AUTHORS COPYING ChangeLog NEWS README TODO
%{_bindir}/inkscape
%{_libdir}/inkscape/extensions/*
%{_datadir}/applications/inkscape.desktop
%{_datadir}/locale/*/LC_MESSAGES/inkscape.mo
%{_datadir}/pixmaps/*
%{_datadir}/inkscape/*
%{_mandir}/man1/*

%changelog
* Thu May 01 2003 Christian Schaller <uraeus@gnome.org>
- Fix up the spec file for current release

* Mon Sep 23 2002 Dag Wieers <dag@wieers.com>
- Update to 0.2.6

* Thu Sep 12 2002 Dag Wieers <dag@wieers.com>
- Update to 0.2.5
- Changed SPEC to benefit from macros

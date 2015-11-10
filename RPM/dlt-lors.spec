%define default_release 1
Name: dlt-lors
Version: 1.0
Release: %{?release}%{!?release:%{default_release}}
Summary: LoRS Library and Command Line Tools

Group:	        Application/System
License:	http://www.apache.org/licenses/LICENSE-2.0
URL:	        https://github.com/datalogistics/dlt-lors
Source0:	%{name}.tar.gz
BuildRoot:	%{_tmppath}/%{name}-%{version}-%{release}

BuildRequires:	cmake gcc libtool autoconf automake wget libuuid-devel curl-devel openssl-devel jansson-devel libunis-c
Requires:	cmake jansson-devel curl-devel openssl-devel libuuid-devel libunis-c libwebsockets 

%description
LoRS (Logistical Runtime System) Library and Command Line Tools. The LoRS library is intended to be included in applications to give them access to exNodes and IBP storage. The LoRS library provides a high level of flexibility for dealing with the lower layers of the Network Storage Stack. The command line LoRS tools allow users to access many of the features provided by the C API without having to do any programming. In case of bug or issue please report it to data-logistics@googlegroups.org

%prep
%setup -n dlt-lors

%build
%configure 
make

%install
%makeinstall

%clean
rm -rf %{buildroot}

%files
%defattr(-,root,root)
%{_bindir}/*
%{_libdir}/*
%{_includedir}/*.h
%{_datadir}/lors/*.tcl
%{_datadir}/lors/*.gif
%{_datadir}/lors/*.pl
%{_datadir}/lors/pkill

%changelog
* Mon Nov 09 2015 <jayaajay@indiana.edu> 1.0-0-dlt-lors
- Initial draft of spec file for dlt-lors package.

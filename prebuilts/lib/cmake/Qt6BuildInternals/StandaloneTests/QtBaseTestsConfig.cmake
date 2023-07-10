# TODO: Ideally this should look for each Qt module separately, with each module's specific version,
# bypassing the Qt6 Config file, aka find_package(Qt6SpecificFoo) repated x times. But it's not
# critical.
find_package(Qt6 6.5.1
             REQUIRED COMPONENTS EntryPointPrivate Core Concurrent Sql Network Xml DBus Gui ExampleIconsPrivate OpenGL Widgets OpenGLWidgets DeviceDiscoverySupportPrivate FbSupportPrivate Test PrintSupport)

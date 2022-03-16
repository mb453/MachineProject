project(MachineLib)

set(SOURCE_FILES
        pch.h
        Machine.h Machine.cpp
        MachineFactory.cpp MachineFactory.h
        MachineStandin.cpp MachineStandin.h
        MachineDialog.cpp MachineDialog.h include/machine-api.h ActualMachine.cpp ActualMachine.h ModifiedMachine.cpp ModifiedMachine.h Machine1.cpp Machine1.h Machine1Factory.cpp Machine1Factory.h Component.cpp Component.h Polygon.cpp Polygon.h Shape.cpp Shape.h Motor.cpp Motor.h Machine2Factory.cpp Machine2Factory.h RotationSource.cpp RotationSource.h Source.cpp Source.h Sink.cpp Sink.h RotationSink.cpp RotationSink.h Gear.cpp Gear.h Arm.cpp Arm.h Rod.cpp Rod.h PositionSource.cpp PositionSource.h PositionSink.cpp PositionSink.h Lever.cpp Lever.h RodSink.cpp RodSink.h INegotiator.h RodSource.cpp RodSource.h Piston.cpp Piston.h)

find_package(wxWidgets COMPONENTS core base xrc html xml REQUIRED)
include(${wxWidgets_USE_FILE})

add_library(${PROJECT_NAME} STATIC ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_precompile_headers(${PROJECT_NAME} PRIVATE pch.h)
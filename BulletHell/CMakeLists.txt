add_executable (BulletHell "BulletHell.cpp" "BulletHell.h" "Player.h" "Player.cpp" "Projectile.h" "Projectile.cpp"   "Weapon.h" "Weapon.cpp"   "ProjectileManager.h" "ProjectileManager.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET BulletHell PROPERTY CXX_STANDARD 20)
endif()

find_package(raylib CONFIG REQUIRED)
target_link_libraries(BulletHell PRIVATE raylib)

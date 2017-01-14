
namespace oe {
namespace dafif { class WaypointLoader; }
}
 
class WaypointTests
{
public:
   WaypointTests(
      const char* country,
      const char* file = "file3",
#ifdef WIN32
      const char* path = "data/dafif/fullall/"
#else
      const char* path = "data/dafif/fullall/"
#endif
   );
   ~WaypointTests();

   void dump();      // dump raw DAFIF records
   void func30();    // just loads records and prints
   void func31(const double acLat, const double acLon, const double acElev, const bool printData);    // test waypoint()
   void func32(const double acLat, const double acLon, const double acElev, const bool printData);    // test queryByIdent()
   void func35(const double acLat, const double acLon, const double acElev, const bool printData);    // test queryByRange()
   void func36(const double acLat, const double acLon, const double acElev, const bool printData);    // test queryByKey()
   void func3A();    // test ICAO sorted listing
   void func3B(const double acLat, const double acLon, const double acElev, const bool printData);    // test queryByIcao()

private:
   oe::dafif::WaypointLoader* db;
};


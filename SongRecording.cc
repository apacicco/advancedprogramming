// COPYRIGHT 2024 apacicco
#include"SongRecording.h"
#include<string>
using std::string;
using std::cout;
using std::endl;

namespace csce240_programming_assignment_5 {
  // DEFAULT CONSTRUCTOR
  SongRecording::SongRecording(string title, string artist, int time, int num)
    : _title("untitled"),
     _artist_num(0),
     _time_in_secs(0),
     _artist_name(nullptr) {
  SetTitle(title);
  SetNumArtists(1);
  SetNumArtists(num);
  SetArtist(artist);
  SetTrackLength(time);
}
// COPY CONSTRUCTOR
SongRecording::SongRecording(const SongRecording& sr) : _title(sr._title),
                            _artist_name(nullptr),
                            _time_in_secs(sr._time_in_secs),
                            _artist_num(0) {
  SetNumArtists(sr._artist_num);
  for ( int i = 0; i < _artist_num; ++i )
    _artist_name[i] = sr._artist_name[i];
  }
// OVERIDED ASSIGNMENT OPERATOR
  SongRecording& SongRecording::operator = (const SongRecording& right) {
  _title = right._title;
  _time_in_secs = right._time_in_secs;
  // _artist_num = right._artist_num;
  SetNumArtists(right._artist_num);
  for ( int i = 0; i < _artist_num; ++i )
    _artist_name[i] = right._artist_name[i];
  return *this;
}
  void SongRecording::SetTitle(string title) {
    if ( title.length() > 0 )
      _title = title;
  }

  void SongRecording::SetNumArtists(int num) {
    if ( num >= 1 && num != _artist_num ) {
    // need to update _chapter_title - Come back to this NEXT!!
      if ( _artist_name != nullptr )
        delete [] _artist_name;
      _artist_name = new string[num];
      for ( int i = 0; i < num; ++i )
        _artist_name[i] = "unknown";
      _artist_num = num;
  }
}

  void SongRecording::SetArtist(string name, int num) {
    if ( name.length() > 0 && (num > 0 && num <= _artist_num) )
         _artist_name[num-1] = name;
}

  string SongRecording::GetArtist(int num) const {
    if (num >= 1 && num <= _artist_num) {
      return _artist_name[num-1];  // I assume +1 because you start at one less
    } else {
        return "out of bounds";
    }
  }

  void SongRecording::SetTrackLength(int length) {
      int temp = _time_in_secs;
      if (length > 0)
          _time_in_secs = length;
      else
          length = temp;
  }


}  // namespace csce240_programming_assignment_5
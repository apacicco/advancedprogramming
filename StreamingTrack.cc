// Copyright 2024 apacicco
#include"StreamingTrack.h"
#include"SongRecording.h"
#include<string>
using std::string;
using std::cout;
using std::endl;


namespace csce240_programming_assignment_5 {
  // DEFAULT CONSTRUCTOR
  StreamingTrack::StreamingTrack(string title, string primary_artist,
    int length, int num_artists, string primary_genre, int num_streams)
    : SongRecording(title, primary_artist, length, num_artists),
    _genre(nullptr),
    _times_streamed(0) {
    _num_genres = 0;
    SetStreams(num_streams);
    AddGenre(primary_genre);
}
// CONSTANT REFERENCE TO SONGRECORDING
StreamingTrack::StreamingTrack(const SongRecording& to_sr, string pg, int nos)
: SongRecording(to_sr), _genre(nullptr),
  _times_streamed(0) {
  _num_genres = 0;
  SetStreams(nos);
  AddGenre(pg);
}
  // COPY CONSTRUCTOR
  StreamingTrack::StreamingTrack(const StreamingTrack& to_copy)
  : SongRecording(to_copy) {
    _genre = nullptr;
    _num_genres = 0;
    _times_streamed = to_copy._times_streamed;
    for ( int i = 0; i < _num_genres; ++i ) {
       AddGenre(to_copy._genre[i]);
    }
  }
  // OVERLOADED ASSIGNMENT OPERATOR

StreamingTrack& StreamingTrack::operator = (const StreamingTrack& right) {
  SongRecording::operator =(right);
  delete [] _genre;
  _num_genres = right._num_genres;
  _times_streamed = right._times_streamed;
  _genre = new string[_num_genres];
  for ( int i = 0; i < _num_genres; ++i )
    _genre[i] = right._genre[i];
  return *this;
}

void StreamingTrack::SetStreams(int set_streams) {
    if ( set_streams >= 0 ) {
      _times_streamed = set_streams;
    }
  }
void StreamingTrack::AddStreams(int add_streams) {
    if ( add_streams > 0 )
        _times_streamed += add_streams;
}

void StreamingTrack::AddGenre(string added) {
    for ( int i = 0; i < _num_genres; ++i ) {
      if (_genre[i] == added)
          return;
}
    ++_num_genres;
    string * temp = _genre;  // old block
    _genre = new string[_num_genres];  // points to a new block
    for ( int i = 0; i < _num_genres-1; ++i ) {
      _genre[i] = temp[i];
    }
    _genre[_num_genres-1] = added;
    delete [] temp;  // deleting the copy
}

  string StreamingTrack::GetGenre(int get) const {
     if ( get > 0 && get <= _num_genres )
      return _genre[get-1];
     return "out of bounds";
  }

bool StreamingTrack::IsGenre(string gen) const {
    for (int i = 0; i < _num_genres; ++i) {
      if ( _genre[i] == gen)
          return true;
    }
    return false;
}

void StreamingTrack::RemoveGenre(string rem) {
    string * temp = _genre;  // old block
    if ( !IsGenre( rem ) )
        return;
    _genre = new string[--_num_genres];  // points to a new block, want to cha
    for ( int i = 0, j = 0; i < _num_genres; ++i, ++j ) {
      if ( temp[j] == rem ) {
        --i;
      } else {
       _genre[i] = temp[j];
      }
    }
    delete [] temp;
}

}  // namespace csce240_programming_assignment_5


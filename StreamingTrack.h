// COPYRIGHT 2024 apacicco
#include"SongRecording.h"
#ifndef _STREAMING_TRACK_H
#define _STREAMING_TRACK_H
#include<string>
using std::string;
#include<iostream>
using std::ostream;
namespace csce240_programming_assignment_5 { // so that if your code is being used w/ someone elses,
// you need not cooridination of names
class StreamingTrack : public SongRecording {
    // friend ostream& operator << (ostream&, const StreamTracking&);
 public:
  explicit StreamingTrack(string title = "untitled",
    string primary_artist = "unknown",
    int track_length = 0, int num_of_artists = 1, string primary_genre = "pop",
    int num_of_streams = 0);
  StreamingTrack(const StreamingTrack& to_copy);
  StreamingTrack(const SongRecording& song_recording_reference,
    string primary_genre = "pop", int num_of_streams = 0);
  StreamingTrack& operator = (const StreamingTrack& right);
  ~StreamingTrack() {
     delete [] _genre;
  }
  // functions
  int GetStreams() const { return _times_streamed; }
  void SetStreams(int num_of_streams);
  void AddStreams(int add);
  int GetNumGenres() const { return _num_genres; }
  string GetGenre(int gen = 1) const;
  bool IsGenre(string gen) const;
  void AddGenre(string added);
  void RemoveGenre(string removed);

 private:
  int _times_streamed;
  string * _genre;
  int _num_genres;
};
}  //  namespace csce240_programming_assignment_5
#endif
// This file Copyright © 2008-2022 Transmission authors and contributors.
// It may be used under the MIT (SPDX: MIT) license.
// License text can be found in the licenses/ folder.

#import <AppKit/AppKit.h>

@class Controller;
@class Torrent;

@interface AddWindowController : NSWindowController

@property(nonatomic, readonly) Torrent* torrent;

// if canToggleDelete is NO, we will also not delete the file regardless of the delete check's state
// (this is so it can be disabled and checked for a downloaded torrent, where the file's already deleted)
- (instancetype)initWithTorrent:(Torrent*)torrent
                          destination:(NSString*)path
                      lockDestination:(BOOL)lockDestination
                           controller:(Controller*)controller
                          torrentFile:(NSString*)torrentFile
    deleteTorrentCheckEnableInitially:(BOOL)deleteTorrent
                      canToggleDelete:(BOOL)canToggleDelete;

- (void)setDestination:(id)sender;

- (void)add:(id)sender;
- (void)cancelAdd:(id)sender;

- (IBAction)setFileFilterText:(id)sender;
- (IBAction)checkAll:(id)sender;
- (IBAction)uncheckAll:(id)sender;

- (void)verifyLocalData:(id)sender;

- (void)changePriority:(id)sender;

- (void)updateCheckButtons:(NSNotification*)notification;

- (void)updateGroupMenu:(NSNotification*)notification;

@end

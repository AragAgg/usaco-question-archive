while (tile_at < tiles_by_depth.size() &&
       tiles[tiles_by_depth[tile_at]] > b.max_depth) {
	auto removed = valid_tiles.find(tiles_by_depth[tile_at]);
	needed_step = max(needed_step, *next(removed) - *prev(removed));
	valid_tiles.erase(removed);
	tile_at++;
}

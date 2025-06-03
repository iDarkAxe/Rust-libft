use libc::c_char;
// use std::ffi::CStr;

// Rust like strlen
/* #[unsafe(no_mangle)]
pub extern "C" fn ft_strlen(s: *const c_char) -> usize {
    if s.is_null() {
        return 0;
    }
    unsafe {
        CStr::from_ptr(s).to_bytes().len()
    }
} */

#[unsafe(no_mangle)]
pub extern "C" fn ft_strlen(s: *const c_char) -> usize {
    if s.is_null() {
        return 0;
    }
    unsafe {
        let mut index: usize = 0;
        while *s.add(index) != 0 
        {
            index += 1;
        }
        return index;
    }
}

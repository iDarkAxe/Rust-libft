#[unsafe(no_mangle)]
pub extern "C" fn ft_isalnum(character: u32) -> u32 {
    if (character >= 'a' as u32 && character <= 'z' as u32) || (character >= 'A' as u32
    && character <= 'Z' as u32) || (character >= '0' as u32 && character <= '9' as u32)
    {
        return 1;
    }
    return 0;
}
